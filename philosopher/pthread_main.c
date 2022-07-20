#include "philosopher.h"

int find_thread_id(t_data *data)
{
    int i;

    i = 0;
    while (++i < data->philo_cnt + 1)
    {
        if (data->philo[i].act == NOT_USE)
            return (i);
    }
    return (-1);
}

void *pthread_main(void *data)
{
    t_data  *d;
    int     id;

    d = (t_data *)data;
    id = d->t_id;
    get_time(data);
    d->philo[id].last_eat = d->time / 1000;
    d->philo[id].status = thinking;
    while (d->end == FALSE)
    {
        get_forks(d, id);
        start_eating(d, id);
        putdown_forks(d, id);
        start_sleeping(d, id);
        start_thinking(d, id);
    }
    return (0);
}


int die_check(t_data *data, int thread_id)
{
    if(data->end == TRUE)
        return (TRUE);
    get_time(data);
    if (data->time - data->philo[thread_id].last_eat > data->time_to_die)
    {
        data->philo->status = die;
        print_status(data, die, thread_id);
        return (TRUE);
    }
    return (FALSE);
}

void    print_status(t_data *data, t_status status, int thread_id)
{
    get_time(data);
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
    else if (status == 10) /////////////////////////////////////// 나중에 지워야 함
        printf("%d %d is END ERROR!!\n", data->time, thread_id + 1);
    else
        printf("printf Error\n");
}

void    get_forks(t_data *data, int thread_id)
{
    int left;
    int right;

    if (data->philo[thread_id].status != thinking)
    {
        printf("%d get_forks ERROR!!\n", thread_id);
        return ;
    }
    if (data->end == TRUE)
    {
        printf("%d END get_forks ERROR!!\n", thread_id);
        return ;
    }
    left = thread_id;
    right = (thread_id + 1)  % data->philo_cnt;
    if (left == right)
        usleep(data->time_to_die);//
    else if (thread_id % 2 == 1)
    {
        pthread_mutex_lock(data->forks[left].mutex);
        // mutex_lock(data->forks, left);
        data->philo[thread_id].fork[0] = 1;
        // mutex_lock(data->forks, right);
        pthread_mutex_lock(data->forks[right].mutex);
        data->philo[thread_id].fork[1] = 1;
    }
    else if (thread_id % 2 == 0)
    {
        // mutex_lock(data->forks, right);
        pthread_mutex_lock(data->forks[right].mutex);
        data->philo[thread_id].fork[1] = 1;
        pthread_mutex_lock(data->forks[left].mutex);
        // mutex_lock(data->forks, left);
        data->philo[thread_id].fork[0] = 1;
    }
    // 죽었는지 확인 // 다른데서 끝났는지
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = getting;
        print_status(data, getting, thread_id);
    }
}

void    start_eating(t_data *data, int thread_id)
{
    // 상태 출력
    //
    if (data->philo[thread_id].status != getting)
    {
        printf("%d start_eating error\n", thread_id); ///////// 나중에 지워주기
        return ; 
    }
    if (data->end == TRUE)
    {
        printf("%d END start_eating error\n", thread_id); ///////// 나중에 지워주기
        return ; 
    }
    if (die_check(data, thread_id))
        return ;
    get_time(data);
    data->philo[thread_id].last_eat = data->time / 1000;
    if (data->end == FALSE)
        data->philo[thread_id].status = eating;
    if (data->end == FALSE)
        print_status(data, eating, thread_id);
    if (data->must_eat != 2147483647)
        data->philo[thread_id].eat_cnt++;
    usleep(data->time_to_eat);
    if (die_check(data, thread_id))
        return ;
}

void    putdown_forks(t_data *data, int thread_id)
{
    int left;
    int right;

    if (data->philo[thread_id].status != eating) 
    {
        printf("%d putdown_forks ERROR!!\n", thread_id);
        return ;
    }
    if(data->end == TRUE)
    {
        printf("%d END putdown_forks ERROR!!\n", thread_id);
        return ;
    }
    left = thread_id;
    right = (thread_id + 1)  % data->philo_cnt;
    // if (thread_id % 2 == 1) // 홀수 짝수 상관없이 그냥 내려놔도 될까?
    // {
    //     // mutex_unlock(data->forks, left);
    //     pthread_mutex_unlock(data->forks[left].mutex);
    //     data->philo[thread_id].fork[0] = 0;
    //     pthread_mutex_unlock(data->forks[right].mutex);
    //     // mutex_unlock(data->forks, right);
    //     data->philo[thread_id].fork[1] = 0;
    // }
    // else if (thread_id % 2 == 0)
    {
        // mutex_unlock(data->forks, right);
        pthread_mutex_unlock(data->forks[right].mutex);
        data->philo[thread_id].fork[1] = 0;
        pthread_mutex_unlock(data->forks[left].mutex);
        // mutex_unlock(data->forks, left);
        data->philo[thread_id].fork[0] = 0;
    }
    if (!die_check(data, thread_id) && data->end == FALSE)
        data->philo[thread_id].status = forksdown;
    printf("%d putdown forks\n", thread_id + 1);
}

void    start_sleeping(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != forksdown)
    {
        printf("%d start_sleeping ERROR!!\n", thread_id);
        return ;
    }
    if (data->end == TRUE)
    {
        printf("%d END start_sleeping ERROR!!\n", thread_id);
        return ;
    }
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = sleeping;
        print_status(data, sleeping, thread_id);
        usleep(data->time_to_sleep);
    }
    if (die_check(data, thread_id))
        return ;
}

void    start_thinking(t_data *data, int thread_id)
{
    if (data->philo[thread_id].status != sleeping)
    {
        printf("%d start_thinking ERROR!!\n", thread_id);
        return ;
    }
    if (data->end == TRUE)
    {
        printf("%d END start_thinking ERROR!!\n", thread_id);
        return ;
    }
    if (!die_check(data, thread_id) && data->end == FALSE)
    {
        data->philo[thread_id].status = thinking;
        print_status(data, thinking, thread_id);
    }   
}

// 잡기 // 먹기 // 내려놓기 // 생각하기 // 죽음

void    get_time(t_data *data)
{
    struct  timeval time;

    gettimeofday(&time, NULL);
    data->time = (int)time.tv_usec / 1000;
}

int    get_curr_time(void)
{
    int             curr_time;
    struct timeval  time;

    gettimeofday(&time, NULL);
    curr_time = (int)time.tv_usec / 1000;
}