#include "philosopher.h"

void    *monitoring_main(void *data)
{
    t_data  *d;
    int     i;
    int     cnt;

    d = (t_data *)data;
    while (d->start == 0);
    while (1)
    {
        i = -1;
        cnt = 0;
        while (++i < d->philo_cnt)
        {
            if (d->philo[i].status == die)
            {
                d->end = TRUE;
                return (NULL);
            }
            if (d->philo[i].eat_cnt == d->must_eat)
                cnt++;
            if (cnt == d->philo_cnt)
            {
                d->end = TRUE;
                return (NULL);
            }
        }
    }
}