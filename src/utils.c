#include "../includes/philo.h"

int is_space(char c)
{
    return (c >= 9 && c <= 13 || c == 32);
}

int	ft_isdigit(char nbr)
{
	return (nbr >= '0' && nbr <= '9');
}