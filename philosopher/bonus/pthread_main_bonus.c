#include "philosopher_bonus.h"

void    *philo_main(t_data *data, int num)
{
    while (data->philo[num].status != die && data->end == FALSE)
    {
        get_forks(data, num);
        start_eating(data, num);
        putdown_forks(data, num);
        start_sleeping(data, num);
        start_thinking(data, num);
        if (data->must_eat == data->philo[num].eat_cnt)
            break ;
    }
    exit(0);
}

int die_check(t_data *data, int thread_id)
{
    if(data->end == TRUE || data->philo->status == die)
        return (TRUE);
    data->time = get_curr_time(data->start_time);
    if (data->time - data->philo[thread_id].last_eat > data->time_to_die)
    {
        data->end = TRUE;
        data->philo->status = die;
        print_status(data, die, thread_id);
        usleep(200);
        kill(data->monitor, SIGINT);
        return (TRUE);
    }
    return (FALSE);
}

int die_check_getfork(t_data *data, int thread_id)
{
    int gap;
    int die_time;

    if(data->end == TRUE)
        return (TRUE);
    usleep(50);
    data->time = get_curr_time(data->start_time);
    gap = data->time - data->philo[thread_id].last_eat;
    die_time = data->time - (gap - data->time_to_die);
    if (gap > data->time_to_die)
    {
        data->end = TRUE;
        data->philo->status = die;
        printf("%d %d is died\n", die_time, thread_id + 1);
        kill(data->monitor, SIGINT);
        return (TRUE);
    }
    return (FALSE);
}

void    print_status(t_data *data, t_status status, int thread_id)
{
    data->time = get_curr_time(data->start_time);
    if (status == -1)
        printf("%d %d is died\n", data->time, thread_id + 1);
    else if (status == 0)
        printf("%d %d is sleeping\n", data->time, thread_id + 1);
    else if (status == 1)
        printf("%d %d is thinking\n", data->time, thread_id + 1);
    else if (status == 2)
        printf("%d %d has taken a fork\n", data->time, thread_id + 1);
    else if (status == 3)
        printf("%d %d is eating\n", data->time, thread_id + 1);
    else
        printf("printf Error\n");
}

void    get_forks(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != thinking || data->end == TRUE)
        return ;
    if (data->philo_cnt == 1)
        put_delay(data, data->time_to_die + 1, thread_id);
    sem_wait(data->fork);
    // if (die_check_getfork(data, thread_id) == TRUE)
        // return ;
    sem_wait(data->fork);
    // if (die_check_getfork(data, thread_id) == TRUE)
        // return ;
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = getting;
        print_status(data, getting, thread_id);
    }
}

void    start_eating(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != getting || data->end == TRUE)
        return ;
    if (die_check(data, thread_id))
        return ;
    data->philo[thread_id].last_eat = get_curr_time(data->start_time);
    if (data->end == FALSE)
    {
        data->philo[thread_id].status = eating;
        print_status(data, eating, thread_id);
        put_delay(data, data->time_to_eat, thread_id);
    }
    if (data->must_eat != 2147483647)
        data->philo[thread_id].eat_cnt++;
    // printf("eat_cnt %d %d\n", thread_id + 1, data->philo[thread_id].eat_cnt);
    if (die_check(data, thread_id))
        return ;
}

void    putdown_forks(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != eating || data->end == TRUE)
        return ;
    sem_post(data->fork);
    sem_post(data->fork);
    if (!die_check(data, thread_id) && data->end == FALSE)
        data->philo[thread_id].status = forksdown;
    printf("%d putdown forks\n", thread_id + 1);
    if (data->philo[thread_id].eat_cnt == data->must_eat)////////
    {
        usleep(500000);
        exit(0);
    }
}

void    start_sleeping(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != forksdown || data->end == TRUE)
        return ;
    if (!die_check(data, thread_id) && data->end == FALSE && \
    data->philo[thread_id].eat_cnt != data->must_eat)
    {
        data->philo[thread_id].status = sleeping;
        print_status(data, sleeping, thread_id);
        put_delay(data, data->time_to_sleep, thread_id);
    }
    if (data->philo[thread_id].eat_cnt == data->must_eat)
        data->philo[thread_id].last_eat = get_curr_time(data->start_time);
    if (die_check(data, thread_id))
        return ;
}

void    start_thinking(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != sleeping || data->end == TRUE)
        return ;
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = thinking;
        print_status(data, thinking, thread_id);
    }   
}

int    get_curr_time(struct timeval start_time)
{
    struct timeval  end_time;
    int             time;

	gettimeofday(&end_time, NULL);
    time = ((end_time.tv_sec * 1000000 + end_time.tv_usec) - \
        (start_time.tv_sec * 1000000 + start_time.tv_usec)) / 1000;
    return (time);
}

int    put_delay(t_data *data, int delay_time, int thread_id)
{
    int curr_time;
    int end_time;

    curr_time = get_curr_time(data->start_time);
    end_time = get_curr_time(data->start_time);
    while(end_time - curr_time < delay_time)
    {
        usleep(300);
        if (die_check(data, thread_id) == TRUE)
            return (TRUE);
        end_time = get_curr_time(data->start_time);
    }
    return (FALSE);
}