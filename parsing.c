

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
