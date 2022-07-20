#include "philosopher.h"

void    *monitoring_main(void *data)
{
    t_data  *d;
    int     i;
    int     cnt;

    d = (t_data *)data;
    cnt = 0;
    while (d->start == 0)

    while (1)
    {
        i = -1;
        while (++i < d->philo_cnt)
        {
            if (d->philo[i].status == die)
            {
                d->end = TRUE;
                return (NULL);
            }
            if (d->philo[i].eat_cnt == d->time_to_eat)
                pthread_detach(d->philo[i].pth);
        }
    }
    return (NULL);
}