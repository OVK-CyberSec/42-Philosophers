/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohifdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:20:58 by mohifdi           #+#    #+#             */
/*   Updated: 2026/02/16 19:22:20 by mohifdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(t_data *data, int ac)
{
	if (data->num_philos < 1 || data->num_philos > 200)
		return (0);
	if (data->time_to_die < 0 || data->time_to_eat < 0)
		return (0);
	if (data->time_to_sleep < 0)
		return (0);
	if (ac == 6 && data->must_eat_count < 0)
		return (0);
	return (1);
}

void	parse_args(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat_count = ft_atoi(av[5]);
	else
		data->must_eat_count = -1;
}

int	parse_inputs(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (0);
	if (ft_atoi(av[1]) > 200)
		return (0);
	i = 2;
	while (i < ac)
	{
		if (!is_numeric(av[i]))
			return (0);
		if (ft_atoi(av[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
