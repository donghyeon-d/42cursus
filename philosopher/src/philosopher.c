/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:48:46 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/28 21:59:13 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*init_data(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->philo_cnt = ft_atoi_positive(argv[1]);
	data->time_to_die = ft_atoi_positive(argv[2]);
	data->time_to_eat = ft_atoi_positive(argv[3]);
	data->time_to_sleep = ft_atoi_positive(argv[4]);
	data->end = FALSE;
	data->must_eat = 2147483647;
	data->start = 0;
	gettimeofday(&data->start_time, NULL);
	data->time = get_curr_time(data->start_time);
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

int	make_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->philo_cnt);
	if (data->philo == NULL)
		return (FALSE);
	i = -1;
	while (++i < data->philo_cnt)
	{
		data->philo[i].status = thinking;
		data->philo[i].eat_cnt = 0;
		data->philo[i].fork[0] = 0;
		data->philo[i].fork[1] = 0;
		data->philo[i].last_eat = data->time;
	}
	return (TRUE);
}

int	make_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_forks) * data->philo_cnt);
	if (data->forks == NULL)
		return (FALSE);
	i = -1;
	while (++i < data->philo_cnt)
	{
		data->forks[i].mutex = malloc(sizeof(pthread_mutex_t));
		if (data->forks[i].mutex == NULL)
			return (FALSE);
		if (pthread_mutex_init(data->forks[i].mutex, NULL) != 0)
			return (FALSE);
	}
	return (TRUE);
}

int	make_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_cnt)
	{
		data->philo[i].pth = malloc(sizeof(pthread_t));
		if (data->philo[i].pth == NULL)
			return (FALSE);
		data->t_id = i;
		if (pthread_create(data->philo[i].pth, NULL, pthread_main, \
					(void *)data) != 0)
			return (FALSE);
		usleep(10);
	}
	data->start = 1;
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 4 || argc > 6)
		return (0);
	data = init_data(argc, argv);
	if (data == NULL)
		return (1);
	if (make_philo(data) == FALSE)
		return (1);
	if (make_forks(data) == FALSE)
		return (1);
	if (make_monitor(data) == FALSE)
		return (1);
	if (make_thread(data) == FALSE)
		return (1);
	pthread_join(*data->monitor, NULL);
	// system("leaks philosopher");
	return (0);
}
