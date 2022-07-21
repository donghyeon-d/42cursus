#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#ifndef PHILOSOPHER_BONUS_H
#define PHILOSOPHER_BONUS_H

typedef struct s_data
{
    sem_t   *fork;
    pid_t   child;
    int     id;
    int     *child_pid;
}   t_data;




#endif