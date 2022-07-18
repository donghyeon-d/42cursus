#include <pthread.h>

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

typedef struct  s_philo
{
    pthread_t **philo;
}   t_philo;

typedef struct  s_data
{
    int philo_cnt;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    int error;
    int *forks;// 1 사용가능  0 사용 중 
    t_philo *philo;
}   t_data;


#endif