/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:21:27 by mohifdi           #+#    #+#             */
/*   Updated: 2026/02/16 19:21:29 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Invalid number of arguments\n");
		printf("Usage: ./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep [number_of_times_each_must_eat]\n");
		return (1);
	}
	if (init_data(&data, ac, av) != 0)
		return (1);
	if (init_forks(&data) != 0)
		return (cleanup(&data), 1);
	if (init_philos(&data) != 0)
		return (cleanup(&data), 1);
	if (create_threads(&data) != 0)
		return (cleanup(&data), 1);
	cleanup(&data);
	return (0);
}
