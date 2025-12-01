#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_info
{
    int     philo_nbr;
    int     tt_eat;
    int     tt_die;
    int     tt_sleep;
    int     limit_of_meals;
    int     start_time;
    bool    philo_died;
}   t_info;

typedef struct s_fork
{
    pthread_mutex_t fork;
    int fork_id;
}   t_fork;

typedef enum e_id_action
{
    LOCK,
    UNLOCK,
    INIT,
    DESTROY,
    CREATE,
    JOIN,
    DETACH,
}   t_id_action;

typedef struct s_philo
{
    int id;
    int meals_counter;
    bool full;
    long last_meal_time;
    t_fork  *left_fork;
    t_fork  *right_fork;
    pthread_t  thread_id;
    t_info  *info;   
}   t_philo;


//  parsing     //
void    parse_inputs(t_info *info, char **av);

//  error handling  //
const char   *verify_inputs(const char *str);
void ft_error(char *str);

//   utils  //
int is_space(char c);
int	ft_isdigit(char nbr);

#endif