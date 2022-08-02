/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:38 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:03:39 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	get_forks(t_data *data, int thread_id)
{
	int	right;

	if (data->philo[thread_id].status != thinking || data->end == TRUE)
		return ;
	right = (thread_id + 1) % data->philo_cnt;
	if (thread_id == right)
		put_delay(data, data->time_to_die + 1, thread_id);
	else if (thread_id % 2 == 1)
	{
		pthread_mutex_lock(data->forks[thread_id].mutex);
		pthread_mutex_lock(data->forks[right].mutex);
	}
	else if (thread_id % 2 == 0)
	{
		pthread_mutex_lock(data->forks[right].mutex);
		pthread_mutex_lock(data->forks[thread_id].mutex);
	}
	if (!die_check(data, thread_id) && data->end == FALSE)
	{
		data->philo[thread_id].fork[0] = 1;
		data->philo[thread_id].fork[1] = 1;
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
	data->philo[thread_id].last_eat = get_curr_time(data->start_time);
	if (data->end == FALSE)
	{
		data->philo[thread_id].status = eating;
		print_status(data, eating, thread_id);
		put_delay(data, data->time_to_eat, thread_id);
	}
	if (data->must_eat != 2147483647)
		data->philo[thread_id].eat_cnt++;
	if (data->end == TRUE || die_check(data, thread_id))
		return ;
}
// printf("eat_cnt %d %d\n", thread_id + 1, data->philo[thread_id].eat_cnt);

void	putdown_forks(t_data *data, int thread_id)
{
	int	left;
	int	right;

	if (data->philo[thread_id].status != eating || data->end == TRUE)
		return ;
	left = thread_id;
	right = (thread_id + 1) % data->philo_cnt;
	if (thread_id % 2 == 1)
	{
		pthread_mutex_unlock(data->forks[left].mutex);
		pthread_mutex_unlock(data->forks[right].mutex);
	}
	else if (thread_id % 2 == 0)
	{
		pthread_mutex_unlock(data->forks[right].mutex);
		pthread_mutex_unlock(data->forks[left].mutex);
	}
	if (!die_check(data, thread_id) && data->end == FALSE)
	{
		data->philo[thread_id].fork[0] = 0;
		data->philo[thread_id].fork[1] = 0;
		data->philo[thread_id].status = forksdown;
	}
}
// printf("%d %d putdown forks\n", 
// get_curr_time(data->start_time), thread_id + 1);

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
		data->philo[thread_id].last_eat = get_curr_time(data->start_time);
	if (data->end == TRUE || die_check(data, thread_id))
		return ;
}

void	start_thinking(t_data *data, int thread_id)
{
	int	left;
	int	right;

	if (data->philo[thread_id].status != sleeping || data->end == TRUE)
		return ;
	left = (thread_id - 1 + data->philo_cnt) % data->philo_cnt;
	right = (thread_id + 1) % data->philo_cnt;
	if (!die_check(data, thread_id) && data->end == FALSE)
	{
		data->philo[thread_id].status = thinking;
		print_status(data, thinking, thread_id);
		while (data->philo[left].fork[1] == 1 || \
				data->philo[right].fork[0] == 1)
		{
			if (data->end == TRUE || die_check(data, thread_id) == TRUE)
				return ;
		}
	}
}
