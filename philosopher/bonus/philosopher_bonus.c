#include "philosopher_bonus.h"

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
    data->end = FALSE;
    data->must_eat = 2147483647;
    data->start = 0;
    gettimeofday(&data->start_time, NULL);
    data->time = get_curr_time(data->start_time);
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

    data->philo = malloc(sizeof(t_philo) * data->philo_cnt);
    if (data->philo == NULL)
        return (FALSE);
    i = -1;
    while (++i < data->philo_cnt)
    {
        data->philo[i].id = i;
        data->philo[i].time = data->time;
        data->philo[i].status = thinking;
        data->philo[i].eat_cnt = 0;
        data->philo[i].last_eat = data->time;
    }
    return (TRUE);
}

int make_forks(t_data *data)
{
    data->fork = malloc(sizeof(sem_t));
    if (data->fork == NULL)
        return (FALSE);
    data->fork = sem_open("/forks", O_CREAT, S_IRUSR, data->philo_cnt);
    if (data->fork == SEM_FAILED)
        return (FALSE);
    return (TRUE);
}

int make_process(t_data *data)
{
    int     i;
    pid_t   pid;

    i = 0;
    gettimeofday(&data->start_time, NULL);
    while (i < data->philo_cnt)
    {
        pid = fork();
        usleep(50);
        if (pid > 0)
        {
            data->philo[i].id = i;
            data->philo[i].pid = pid;
            data->philo[i].use = 1;
            i++;
        }
        else if (pid == 0)
        {
            philo_main(data, i);
            exit(0);
        }
        else
            return (FALSE);
    }
    data->start = 1;
    return (TRUE);
}

void    all_waitpid(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_cnt)
        waitpid(data->philo[i].pid, NULL, 0);
}

int kill_child(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_cnt)
    {
        kill(data->philo[i].pid, SIGINT);
        waitpid(data->philo[i].pid, NULL, 0);
    }
    return (TRUE);
}

int make_monitor(t_data *data)
{
    pid_t   pid;

    pid = fork();
    if (pid > 0)
        while (1);
    else if (pid == 0)
        data->monitor = pid;
    else
        return (FALSE);
    return (TRUE);
}

int main(int argc, char *argv[])
{
    t_data *data;

    sem_unlink("/forks");
    if (argc < 4 || argc > 6)
        return (0);
    data = init_data(argc, argv);
    if (data == NULL)
        return (1);
    if (make_monitor(data) == FALSE)
        return (1);
    if (make_philo(data) == FALSE)
        return (1);
    if (make_forks(data) == FALSE)
        return (1);
    if (make_process(data) == FALSE)
        return (1);
    waitpid(data->monitor, NULL, 0);
    kill_child(data);
    sem_close(data->fork);
    sem_unlink("/forks");
    return (0);
}