#include "philosopher_bonus.h"

void    init_monitoring(t_data *data)
{
    pid_t   pid;
    
    pid = fork();
    usleep(100);
    printf("! %d !", pid);
    if (pid == 0)
    {
        printf("# ");
        while (data->start == 0);
        monitoring_main(data);
        exit(0);
    }
    else
        data->monitor = pid;
}


void    monitoring_main(t_data *data)
{
    int     i;
    int     cnt;

    printf("#");
    while (data->end == FALSE)
    {
        i = -1;
        cnt = 0;
        while (++i < data->philo_cnt && data->end == FALSE)
        {
            if (data->philo[i].status == die)
            {
                data->end = TRUE;
                break ;
            }
            if (data->philo[i].eat_cnt == data->must_eat)
                cnt++;
            if (cnt == data->philo_cnt)
            {
                data->end = TRUE;
                printf("@");
                break ;
            }
        }
    }
    i = -1;
    while (++i < data->philo_cnt)
        kill(data->philo[i].pid, SIGKILL);
}

// void    monitoring_main(t_data *data)
// {
//     int     i;
//     int     cnt;

//     // while (data->start == 0);
//     while (1)
//     {
//         i = -1;
//         cnt = 0;
//         while (++i < data->philo_cnt)
//         {
//             if (data->philo[i].status == die)
//             {
//                 data->end = TRUE;
//                 return ;
//             }
//             if (data->philo[i].eat_cnt == data->must_eat)
//                 cnt++;
//             if (cnt == data->philo_cnt)
//             {
//                 data->end = TRUE;
//                 return ;
//             }
//         }
//     }
// }

void    monitoring(t_data *data)
{
    int flag = 1;
    int add = 0;

    while (flag == 1)
    {
        for (int i = 0; i < data->philo_cnt; i++)
        {
            printf("%d %d %d %d %d\n", i, data->philo[i].use, data->philo[i].status, data->philo[i].eat_cnt, data->must_eat);
            if (data->philo[i].use == 1 && (data->philo[i].status == die || data->philo[i].eat_cnt == data->must_eat))
            {
                kill(data->philo[i].pid, SIGKILL);
                printf("KILL %d\n", i);
                data->philo[i].use = 0;
            }
        }
        add = 0;
        for (int i = 0; i < data->philo_cnt; i++)
        {
            add += data->philo[i].use;
        }
        if (add == 0)
            flag = 0;
        // printf("   ing   %d", flag);
    }
}