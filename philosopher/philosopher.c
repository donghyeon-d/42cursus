#include "philosopher.h"

// number_of_philosophers // time_to_die // time_to_eat // time_to_sleep // numbet_of_times_each_philosopher_must_eat

t_data  *init_data(int argc, char *argv[])
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (data == NULL)
        return (NULL);
    data->philo_cnt = ft_atoi_positive(argv[1]);
    data->time_to_die = ft_atoi_positive(argv[2]);
    data->time_to_eat = ft_atoi_positive(argv[3]);
    data->time_to_sleep = ft_atoi_positive(argv[4]);
    data->error = 0;
    data->must_eat = 2147483647;
    if (argc == 6)
        data->must_eat = ft_atoi_positive(argv[5]);
    if (data->philo_cnt == -1 || data->time_to_die == -1 || \
    data->time_to_eat == -1 || data->time_to_sleep == -1 || \
    data->must_eat == -1)
    {
        free(data);
        data = NULL;
    }
    return (data);
}

int make_philo(t_data *data)
{
    int i;

    i = 0;
    data->philo = malloc(sizeof(t_philo) * data->philo_cnt + 1);
    if (data->philo == NULL)
        return (FALSE);
    gettimeofday(&(data->time), NULL);
    data->philo[0].id = 0;
    data->philo->t = data->time;
    data->philo->status = master;
    data->philo->act = NOT_USE;
    data->philo->last_eat = 0;
    while (++i < data->philo_cnt)
    {
        data->philo[i].id = i;
        data->philo->t = data->time;
        data->philo->status = thinking;
        data->philo->act = NOT_USE;
        data->philo->last_eat = data->philo->t.tv_usec;
    }
    return (TRUE);
}

int make_forks(t_data *data)
{
    int i;

    data->forks = malloc(sizeof(t_forks) * data->philo_cnt + 1);
    if (data->forks == NULL)
        return (FALSE);
    i = 0;
    while (++i < data->philo_cnt + 1)
    {
        data->forks[i].idx = i;
        data->forks[i].status = NOT_USE;
        data->forks[i].mutex = malloc(sizeof(pthread_mutex_t));
        if (data->forks[i].mutex == NULL)
            return (FALSE);
        if (pthread_mutex_init(data->forks[i].mutex, NULL) != 0)
            return (FALSE);
        if (mutex_lock(data->forks, i) != 0)
            return (FALSE);
    }
    return (TRUE);
}

int mutex_lock(t_forks *forks, int idx)
{
    if (pthread_mutex_lock(forks[idx].mutex) != 0)
        return (FALSE);
    forks[idx].status = USE;
    return (TRUE);
}

int mutex_unlock_all(t_data *data)
{
    int i = 0;

    while (i++ < data->philo_cnt + 1)
    {
        if (mutex_unlock(data->forks, i) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}

int mutex_unlock(t_forks *forks, int idx)
{
    if (pthread_mutex_unlock(forks[idx].mutex) != 0)
        return (FALSE);
    forks[idx].status = NOT_USE;
    return (TRUE);
}

int make_thread(t_data *data)
{
    int i;

    i = 0;
    while (++i < data->philo_cnt)
    {
        data->philo[i].pth = malloc(sizeof(pthread_t));
        if (data->philo[i].pth == NULL)
            return (FALSE);
        data->t_id = i;
        if (pthread_create(data->philo[i].pth, NULL, pthread_main, (void *)data) != 0)
            return (FALSE);
        data->philo[i].fork[0] = 0;
        data->philo[i].fork[1] = 0;
        usleep(100);
    }
    return (TRUE);
}

int main(int argc, char *argv[])
{
    t_data *data;

    if (argc < 5 || argc > 6)
        return (0);
    // get argv
    data = init_data(argc, argv);
    // make philo
    if (make_philo(data) == FALSE)
        return (1);
    // make forks (make mutex) // fork lock
    if (make_forks(data) == FALSE);
        return (1);
    // make thread
    if (make_thread(data) == FALSE);
        return (1);
    // fork unlock
    if (mutex_unlock_all(data) == FALSE)
        return (1);
        // thread active
    // join

}