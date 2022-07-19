#include <pthread.h>
#include <sys/time.h>

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

typedef enum e_status {
    sleep = 0,
    thinking = 1,
    fork = 2,
    eating = 3,
    die = -1
} t_status;

typedef struct  s_philo
{
    pthread_t       *philo;
    int             id;
    struct timeval  t;
    t_status        status;
    int             last_eat;
}   t_philo;

typedef struct  s_forks
{
    int             idx;
    int             status;
    pthread_mutex_t *forks;
} t_forks;

typedef struct  s_data
{
    int     philo_cnt;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     must_eat;
    int     error;
    struct  timeval time;
    t_philo *philo;
    t_forks *forks;
}   t_data;


#endif