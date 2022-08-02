/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_act_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:47:15 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:57:54 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	get_forks(t_data *data, int thread_id)
{
	if (data->philo[thread_id].status != thinking || data->end == TRUE)
		return ;
	if (data->philo_cnt == 1)
		put_delay(data, data->time_to_die + 1, thread_id);
	pthread_create(&(data->philo[thread_id].pth), NULL, ps_check, (void *)data);
	sem_wait(data->fork);
	sem_wait(data->fork);
	pthread_detach(data->philo[thread_id].pth);
	pthread_join(data->philo[thread_id].pth, NULL);
	if (!die_check(data, thread_id) && data->end == FALSE)
	{
		data->philo[thread_id].status = getting;
		print_status(data, getting, thread_id);
	}
}

void	start_eating(t_data *data, int thread_id)
{
	if (data->philo[thread_id].status != getting || data->end == TRUE)
		return ;
	if (die_check(data, thread_id))
		return ;
	data->philo[thread_id].last_eat = get_curr_time(data->start_time, data);
	if (data->end == FALSE)
	{
		data->philo[thread_id].status = eating;
		print_status(data, eating, thread_id);
		put_delay(data, data->time_to_eat, thread_id);
	}
	if (data->must_eat != 2147483647)
		data->philo[thread_id].eat_cnt++;
	if (die_check(data, thread_id))
		return ;
}

void	putdown_forks(t_data *data, int thread_id)
{
	if (data->philo[thread_id].status != eating || data->end == TRUE)
		return ;
	sem_post(data->fork);
	sem_post(data->fork);
	if (!die_check(data, thread_id) && data->end == FALSE)
		data->philo[thread_id].status = forksdown;
	if (data->philo[thread_id].eat_cnt == data->must_eat)
	{
		data->philo[thread_id].last_eat = get_curr_time(data->start_time, data);
		usleep(data->time_to_die * 1000);
		kill(data->monitor, SIGINT);
	}
}
// printf("%d putdown forks\n", thread_id + 1);
// printf("eat.cnt [%d], %d\n", thread_id + 1, data->philo[thread_id].eat_cnt);

void	start_sleeping(t_data *data, int thread_id)
{
	if (data->philo[thread_id].status != forksdown || data->end == TRUE)
		return ;
	if (!die_check(data, thread_id) && data->end == FALSE && \
			data->philo[thread_id].eat_cnt != data->must_eat)
	{
		data->philo[thread_id].status = sleeping;
		print_status(data, sleeping, thread_id);
		put_delay(data, data->time_to_sleep, thread_id);
	}
	if (data->philo[thread_id].eat_cnt == data->must_eat)
		data->philo[thread_id].last_eat = get_curr_time(data->start_time, data);
	if (die_check(data, thread_id))
		return ;
}

void	start_thinking(t_data *data, int thread_id)
{
	if (data->philo[thread_id].status != sleeping || data->end == TRUE)
		return ;
	if (!die_check(data, thread_id) && data->end == FALSE)
	{
		data->philo[thread_id].status = thinking;
		print_status(data, thinking, thread_id);
	}
}
