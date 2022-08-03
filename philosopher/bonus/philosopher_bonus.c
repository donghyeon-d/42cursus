/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:43:23 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/03 10:19:44 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

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
	data->id = 0;
	gettimeofday(&data->start_time, NULL);
	data->time = get_curr_time(data->start_time, data);
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
		data->philo[i].last_eat = data->time;
	}
	return (TRUE);
}

int	make_forks(t_data *data)
{
	data->fork = sem_open("/forks", O_CREAT, S_IRUSR, data->philo_cnt);
	if (data->fork == SEM_FAILED)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	sem_unlink("/forks");
	if (argc < 4 || argc > 6)
		return (0);
	data = init_data(argc, argv);
	if (data == NULL)
		return (1);
	if (make_monitor(data) == FALSE)
		return (1);
	if (make_philo(data) == FALSE)
		return (1);
	if (make_forks(data) == FALSE)
		return (1);
	if (make_process(data) == FALSE)
		return (1);
	waitpid(data->monitor, NULL, 0);
	kill_child(data);
	sem_close(data->fork);
	sem_unlink("/forks");
	system("leaks philosopher_bonus");
	return (0);
}
