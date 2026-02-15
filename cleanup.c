#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
}

void	cleanup(t_data *data)
{
	if (data->forks)
	{
		destroy_mutexes(data);
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
}
