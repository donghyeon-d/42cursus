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
    get_forks(d, id);

    // 홀수면 집어
        // forks lock, last_eat 수정, 
    // 
}


int die_check(t_data *data, int thread_id)
{
    // 
    // 현재시간 - 마지막 식사 < time_to_die
}

void get_forks(t_data *data, int thread_id)
{
    int left;
    int right;

    left = thread_id - 1;
    if (left < 1)
        left += data->philo_cnt;
    right = thread_id + 1;
    if (right > data->philo_cnt)
        right %= data->philo_cnt;
    if (thread_id % 2 == 1)
    {
        mutex_lock(&data->forks[thread_id], left);
        data->philo->fork[0] = 1;
        mutex_lock(&data->forks[thread_id], right);
        data->philo->fork[1] = 1;
    }
    else if (thread_id % 2 == 0)
    {
        mutex_lock(&data->forks[thread_id], right);
        data->philo->fork[1] = 1;
        mutex_lock(&data->forks[thread_id], left);
        data->philo->fork[0] = 1;
    }
    data->philo->status = getting;
    // 죽었는지 확인
    // 상태 출력
}

// 잡기 // 먹기 // 내려놓기 // 생각하기 // 죽음