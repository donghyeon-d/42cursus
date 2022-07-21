#include "philosopher_bonus.h"



// int make_process(t_data *data)
// {
//     int     i;
//     pid_t   pid;

//     i = 0;
//     printf("cnt : %d\n", data->philo_cnt);
//     while (i < data->philo_cnt)
//     {
//         pid = fork();
//         printf ("[%d %d]\n", i, pid);
//         usleep(100);
//         if (pid > 0)
//         {
//             data->philo[i].id = i;
//             data->philo[i].pid = pid;
//             i++;
//         }
//         else if (pid == 0)
//         {
//             philo_main(data, i);
//             exit(0);
//         }
//         else
//             return (FALSE);
//     }
//     printf("!!");
//     data->start = 1;
//     return (TRUE);
// }

int main()
{
    pid_t   *pid;
    pid_t   f;
    int     i;

    pid = malloc(sizeof(pid_t) * 5);

    i = 0;
    while (i < 5)
    {
        f = fork();
        printf ("[%d %d]\n", i, f);
        usleep(100);
        if (f > 0)
        {
            pid[i] = f;
            i++;
        }
        else if (f == 0)
        {
            printf("child i %d p %d\n", i, (int)f);
            exit(0);
        }
        else
            return (FALSE);
    }
    printf("!!\n");
    sleep(1);
    printf("end\n");
    sleep(1);
    printf("end\n");
    sleep(1);
    printf("end\n");
    // data->start = 1;
    return (TRUE);
}