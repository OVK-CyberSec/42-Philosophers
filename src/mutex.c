#include "../includes/philo.h"





void    mutex_handle(pthread_mutex_t *mutex, t_id_action action)
{
    if (action == LOCK)
        pthread_mutex_lock(mutex);
    else if (action == UNLOCK)
        pthread_mutex_unlock(mutex);
    else if (action == INIT)
        pthread_mutex_init(mutex, NULL);
    else if (action == DESTROY)
        pthread_mutex_destroy(mutex);
    else
        ft_error("Wrong id_action");
} 