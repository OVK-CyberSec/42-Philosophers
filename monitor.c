#include "philo.h"

int	check_death(t_data *data)
{
	int		i;
	long	time_since_meal;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		time_since_meal = get_time() - data->philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_lock);
		if (time_since_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->dead_flag = true;
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_lock(&data->write_lock);
			printf("%ld %d died\n", get_time() - data->start_time,
				data->philos[i].id);
			pthread_mutex_unlock(&data->write_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_all_ate(t_data *data)
{
	int	i;
	int	finished;

	if (data->must_eat_count == -1)
		return (0);
	i = 0;
	finished = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].meals_eaten >= data->must_eat_count)
			finished++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (finished == data->num_philos)
	{
		pthread_mutex_lock(&data->dead_lock);
		data->dead_flag = true;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data) || check_all_ate(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
