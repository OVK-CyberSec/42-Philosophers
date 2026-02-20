/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:21:03 by mohifdi           #+#    #+#             */
/*   Updated: 2026/02/16 19:23:03 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long			start_time;
	bool			dead_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philos;
}	t_data;

/* Initialization */
int		init_data(t_data *data, int ac, char **av);
int		init_philos(t_data *data);
int		init_forks(t_data *data);

/* Parsing */
int		is_numeric(char *str);
int		validate_args(t_data *data, int ac);
void	parse_args(t_data *data, int ac, char **av);
int		parse_inputs(int ac, char **av);

/* Threads */
int		create_threads(t_data *data);
void	*philosopher_routine(void *arg);

/* Actions */
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/* Monitor */
void	*monitor_routine(void *arg);
int		check_death(t_data *data);
int		check_all_ate(t_data *data);

/* Utils */
long	get_time(void);
void	print_status(t_philo *philo, char *status);
void	ft_usleep(long milliseconds);
int		ft_atoi(const char *str);
bool	is_dead(t_philo *philo);

/* Cleanup */
void	cleanup(t_data *data);
void	destroy_mutexes(t_data *data);

#endif
