#include "philosopher.h"

void *pthread_main(void *data)
{
    t_data  *d;
    int     id;

    d = (t_data *)data;
    id = d->t_id;
    // printf("%d %ld %d\n",id, d->philo[id].start_time.tv_sec, d->philo[id].start_time.tv_usec);
    gettimeofday(&(d->philo[id].start_time), NULL);//
    while (d->end == FALSE)
    {
        get_forks(d, id);
        start_eating(d, id);
        putdown_forks(d, id);
        start_sleeping(d, id);
        start_thinking(d, id);
        if (d->must_eat == d->philo[id].eat_cnt)
            break ;
    }
    return (0);
}

int die_check(t_data *data, int thread_id)
{
    if(data->end == TRUE)
        return (TRUE);
    usleep(100);
    // data->time = get_curr_time(data->start_time);
    data->philo[thread_id].time = get_curr_time(data->philo[thread_id].start_time);
    if (data->philo[thread_id].time - data->philo[thread_id].last_eat > data->time_to_die)//(data->time - data->philo[thread_id].last_eat > data->time_to_die)
    {

        usleep(500);
        if (data->end != TRUE)
            print_status(data, die, thread_id);
        data->philo->status = die;
        data->end = TRUE;
        return (TRUE);
    }
    return (FALSE);
}

// void    print_status(t_data *data, t_status status, int thread_id)
// {
//     // data->time = get_curr_time(data->start_time);
//     data->time = get_curr_time(data->philo[thread_id].start_time);//
//     if (status == -1)
//         printf("%d %d is died\n", data->time, thread_id + 1);
//     else if (status == 0)
//         printf("%d %d is sleeping\n", data->time, thread_id + 1);
//     else if (status == 1)
//         printf("%d %d is thinking\n", data->time, thread_id + 1);
//     else if (status == 2)
//         printf("%d %d has taken a fork\n", data->time, thread_id + 1);
//     else if (status == 3)
//         printf("%d %d is eating\n", data->time, thread_id + 1);
//     else
//         printf("printf Error\n");
// }

void    print_status(t_data *data, t_status status, int thread_id)
{
    data->philo[thread_id].time = get_curr_time(data->philo[thread_id].start_time);//
    if (status == -1)
        printf("%d %d is died\n", data->philo[thread_id].time, thread_id + 1);
    else if (status == 0)
        printf("%d %d is sleeping\n", data->philo[thread_id].time, thread_id + 1);
    else if (status == 1)
        printf("%d %d is thinking\n", data->philo[thread_id].time, thread_id + 1);
    else if (status == 2)
        printf("%d %d has taken a fork\n", data->philo[thread_id].time, thread_id + 1);
    else if (status == 3)
        printf("%d %d is eating\n", data->philo[thread_id].time, thread_id + 1);
    else
        printf("printf Error\n");
}

void    get_forks(t_data *data, int thread_id)
{
    int right;

    if (data->philo[thread_id].status != thinking || data->end == TRUE)
        return ;
    usleep(50);
    right = (thread_id + 1) % data->philo_cnt;
    if (thread_id == right)
        put_delay(data, data->time_to_die + 1, thread_id);
    else if (thread_id % 2 == 1)
    {
        pthread_mutex_lock(data->forks[thread_id].mutex);
        pthread_mutex_lock(data->forks[right].mutex);
    }
    else if (thread_id % 2 == 0)
    {
        pthread_mutex_lock(data->forks[right].mutex);
        pthread_mutex_lock(data->forks[thread_id].mutex);
    }
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].fork[0] = 1;
        data->philo[thread_id].fork[1] = 1;
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
    // data->philo[thread_id].last_eat = get_curr_time(data->start_time);
    data->philo[thread_id].last_eat  = get_curr_time(data->philo[thread_id].start_time);//
    if (data->end == FALSE)
    {
        data->philo[thread_id].status = eating;
        print_status(data, eating, thread_id);
        put_delay(data, data->time_to_eat, thread_id);
    }
    if (data->must_eat != 2147483647)
        data->philo[thread_id].eat_cnt++;
    // printf("eat_cnt %d %d\n", thread_id + 1, data->philo[thread_id].eat_cnt);
    if (data->end == TRUE || die_check(data, thread_id))
        return ;
}

void    putdown_forks(t_data *data, int thread_id)
{
    int left;
    int right;

    if (data->philo[thread_id].status != eating || data->end == TRUE)
        return ;
    left = thread_id;
    right = (thread_id + 1)  % data->philo_cnt;
    if (thread_id % 2 == 1)
    {
        pthread_mutex_unlock(data->forks[left].mutex);
        pthread_mutex_unlock(data->forks[right].mutex);
    }
    else if (thread_id % 2 == 0)
    {
        pthread_mutex_unlock(data->forks[right].mutex);
        pthread_mutex_unlock(data->forks[left].mutex);
    }
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].fork[0] = 0;
        data->philo[thread_id].fork[1] = 0;
        // data->forks[thread_id].status = NOT_USE;
        // data->forks[right].status = NOT_USE;
        data->philo[thread_id].status = forksdown;
    }
    printf("%d putdown forks\n", thread_id + 1);
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
        data->philo[thread_id].last_eat = get_curr_time(data->philo[thread_id].start_time); //
        // data->philo[thread_id].last_eat = get_curr_time(data->start_time);
    if (data->end == TRUE || die_check(data, thread_id))
        return ;
}

void    start_thinking(t_data *data, int thread_id)
{
    int left;
    int right;

    if (data->philo[thread_id].status != sleeping || data->end == TRUE)
        return ;
    // left = (thread_id - 1 + data->philo_cnt) % data->philo_cnt;
    left = thread_id;
    right = (thread_id + 1) % data->philo_cnt;
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = thinking;
        print_status(data, thinking, thread_id);
        while (data->philo[left].fork[1] == 1 || data->philo[right].fork[0] == 1)
        {
            if (data->end == TRUE || die_check(data, thread_id) == TRUE)
                return ;
        }
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

    curr_time = get_curr_time(data->philo[thread_id].start_time);//data->start_time);
    end_time = get_curr_time(data->philo[thread_id].start_time);//data->start_time);
    // printf("start | end : %d %d\n", curr_time, end_time);
    while(end_time - curr_time < delay_time)
    {
        // usleep(90);
        if (data->end == TRUE || die_check(data, thread_id) == TRUE)
            return (TRUE);
        end_time = get_curr_time(data->philo[thread_id].start_time);//data->start_time);
    }
    return (FALSE);
}