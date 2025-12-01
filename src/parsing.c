#include "../includes/philo.h"

static int ft_atol(const char *str)
{
    int nbr;

    nbr = 0;
    str = verify_inputs(str);
    while (!(ft_isdigit(*str)))
    {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }
    if (nbr > INT_MAX)
        ft_error("size limit of INT_MAX reached");
    return (nbr);
}

void    parse_inputs(t_info *info, char **av)
{
    info->philo_nbr = ft_atol(av[1]);
    info->tt_die = ft_atol(av[2]) * 1000 ;
    info->tt_eat = ft_atol(av[3]) * 1000 ;
    info->tt_sleep = ft_atol(av[4]) * 1000 ;
    if (info->tt_eat < 60000
        || info->tt_die < 60000
        || info->tt_sleep < 60000)
        ft_error("Use timestamps major than 60ms");
    if(av[5])
        info->limit_of_meals = ft_atol(av[5]);
    else
        info->limit_of_meals = -1;
}