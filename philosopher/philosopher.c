#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosopher.h"
// #include "../ft_libft/libft.h"

// number_of_philosophers // time_to_die // time_to_eat // time_to_sleep // numbet_of_times_each_philosopher_must_eat

int ft_isdigit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

int	ft_atoi_positive(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
    if (str == NULL)
        return (-1);
	while (str[i] != '\0')
	{
        if (ft_isdigit(str[i]) == 0)
        {
            result = -1;
            break ;
        }
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void    philo_setting(t_data *data)
{
    int i;

    data->philo = malloc(sizeof(t_philo));
    if (data->philo == NULL)
    {
        data->error = 1;
        return ;
    }    
    data->philo->philo = malloc(sizeof(pthread_t *) * data->philo_cnt);
    if (data->philo->philo == NULL)
    {
        data->error = 1;
        return ;
    }
    data->forks = malloc(sizeof(int) * data->philo_cnt);
    if (data->forks == NULL)
    {
        free(data->philo->philo);
        data->error = 1;
        return ;
    }
    i = -1;
}

void *make_thread_handler(void *i)
{
    t_data *data;
    int a = -1;

    data = (t_data *)i;
    int id = data->philo->philo_id;
    printf("I'm %d philo\n", id);
    gettimeofday(&data->philo[id].t, NULL);
    printf ("%d\n", data->philo[id].t.tv_usec - data->time.tv_usec);
    (data->forks)[id].forks = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init((data->forks)[id].forks, NULL);
    if (id != 1)
        a = pthread_mutex_lock((data->forks)[id].forks);
    else if (id == 1)
    {
        while (a != 0)
            a = pthread_mutex_lock((data->forks)[0].forks);
    }
        // a = pthread_mutex_lock((data->forks)[0].forks);
    if (a == 0)
        printf("%d locked\n", id);
    sleep(3);
    a = pthread_mutex_unlock((data->forks)[id].forks);
    if (a == 0)
        printf("%d unlocked %d\n", id, a);
    a = pthread_mutex_unlock((data->forks)[id].forks);
    if (a == 0)
        printf("%d unlocked %d\n", id, a);
    // if (id > 0)
        // pthread_mutex_init((data->forks)[id - 1].forks, NULL);
    gettimeofday(&data->philo[id].t, NULL);
    printf ("%d\n", data->philo[id].t.tv_usec - data->time.tv_usec);
    return (NULL);
}

t_data  *init_data(int argc, char *argv[])
{
    t_data *data;

    if (argc < 5 || argc > 6)
        return (NULL);
    data = malloc(sizeof(t_data));
    if (data == NULL)
        return (NULL);
    data->philo_cnt = ft_atoi_positive(argv[1]);
    philo_setting(data);
    data->time_to_die = ft_atoi_positive(argv[2]);
    data->time_to_eat = ft_atoi_positive(argv[3]);
    data->time_to_sleep = ft_atoi_positive(argv[4]);
    data->error = 0;
    data->forks = malloc(sizeof(t_forks));
    if (data->forks == NULL)
        data->error = 1;
    data->must_eat = 2147483647;
    if (argc == 6)
        data->must_eat = ft_atoi_positive(argv[5]);
    if (data->philo_cnt == -1 || data->time_to_die == -1 || \
    data->time_to_eat == -1 || data->time_to_sleep == -1 || \
    data->must_eat == -1)
    {
        free(data);
        data = NULL;
    }
    return (data);
}

int main(int argc, char *argv[])
{
    t_data *data;
    int a;

    data = init_data(argc, argv);
    if (data == NULL || data->error == 1)
    {
        printf("argv!\n");
        return (0);
    }
    gettimeofday(&data->time, NULL);
    for (int i = 0; i < data->philo_cnt; i++)
    {
        data->philo->philo_id = i;
        a = pthread_create(&data->philo->philo[i], NULL, make_thread_handler, (void *)data);
        sleep(1);
    }
    // a = pthread_join((data->philo->philo)[0], NULL);
    // pthread_mutex_t *f = malloc(sizeof(pthread_mutex_t));
    // a = pthread_mutex_init(f, NULL);
    // printf
    for (int i = 0; i < data->philo_cnt; i++)
    {
            (data->forks)[i].forks = malloc(sizeof(pthread_mutex_t));
        a = pthread_mutex_init((data->forks)[i].forks, NULL);
    }
    sleep(1);
    for (int i = 0; i < data->philo_cnt; i++)
        pthread_join(data->philo->philo[i], NULL);
    return (0);
}