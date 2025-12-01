#include "../includes/philo.h"

const char   *verify_inputs(const char *str)
{
    int len;
    const char  *nbr;

    len = 0;
    while(is_space(*str))
        str++;
    if (*str == '+')
        str++;
    else if (*str == '-')
        ft_error("Negative inputs detected");
    nbr = str;
    while (is_digit(*str++))
        len++;
    if (len > 10)
        ft_error("size limit of INT_MAX reached");
    return (nbr);
}

void ft_error(char *str)
{
    printf("%s",str);
    exit(EXIT_FAILURE);
}