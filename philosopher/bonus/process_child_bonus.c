/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:49:29 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 17:22:21 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	make_process(t_data *data)
{
	int		i;
	pid_t	pid;

	i = -1;
	pid = 0;
	gettimeofday(&data->start_time, NULL);
	while (++i < data->philo_cnt)
	{
		data->id = i;
		data->philo[i].use = 1;
		pid = fork();
		usleep(100);
		if (pid > 0)
			data->philo[i].pid = pid;
		else if (pid == 0)
		{
			philo_main(data, i);
			exit(0);
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int	kill_child(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_cnt)
	{
		kill(data->philo[i].pid, SIGINT);
		waitpid(data->philo[i].pid, NULL, 0);
	}
	return (TRUE);
}

void	*ps_check(void *data)
{
	t_data	*d;
	int		curr_time;

	d = (t_data *)data;
	curr_time = get_curr_time(d->start_time, data);
	while (1)
	{
		if (die_check(d, d->id) == TRUE)
			break ;
		curr_time = d->time;
		if (curr_time > d->philo[d->id].last_eat + d->time_to_die)
		{
			break ;
		}
	}
	return (NULL);
}
