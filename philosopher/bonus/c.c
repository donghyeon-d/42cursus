// cc c.c -Wall -Wextra -Werror -pthread -g

#include "c.h"


int philo_main(t_data *data)
{
    int id = data->id;

    sem_wait(data->fork);
    printf("%d get 1\n", id);
    sem_wait(data->fork);
    printf("%d get 2\n", id);
    printf("%d eat\n", id);
    sem_post(data->fork);
    printf("%d return 1\n", id);
    sem_post(data->fork);
    printf("%d return 2\n", id);
    printf("%d complete\n", id);
    exit(0);
}

int main()
{
    // sem open
    // sem use
    // sem close
    t_data *data;
    pid_t   temp;

    data = malloc(sizeof(t_data));
    data->fork = malloc(sizeof(sem_t));
    data->child_pid = malloc(sizeof(int) * 5);
    sem_unlink("~/42cursus/forks");
    data->fork = sem_open("~/42cursus/forks", O_CREAT, S_IRUSR, 3);
    for (int i = 0; i < 5; i++)
    {
        temp = fork();
        if (temp == 0)
        {
            data->id = i;
            data->child_pid[i] = temp;
            philo_main(data);
            break ;
        }
        else
        {
            printf("!! %d\n", i);
        }
    }
        waitpid(data->child_pid[0], NULL, 0);
        waitpid(data->child_pid[1], NULL, 0);
        waitpid(data->child_pid[2], NULL, 0);
        waitpid(data->child_pid[3], NULL, 0);
        waitpid(data->child_pid[4], NULL, 0);
        // 모니터, 프로세스 킬
        // waitpid

    
}
