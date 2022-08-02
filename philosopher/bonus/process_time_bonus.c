/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_time_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:50:49 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:50:58 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	get_curr_time(struct timeval start_time, t_data *data)
{
	struct timeval	end_time;
	int				time;

	gettimeofday(&end_time, NULL);
	time = (((end_time.tv_sec * 1000000 + end_time.tv_usec) - \
	(start_time.tv_sec * 1000000 + start_time.tv_usec)) / 1000) - \
	(data->id / 10);
	return (time);
}

int	put_delay(t_data *data, int delay_time, int thread_id)
{
	int	curr_time;
	int	end_time;

	curr_time = get_curr_time(data->start_time, data);
	end_time = get_curr_time(data->start_time, data);
	while (end_time - curr_time < delay_time)
	{
		if (die_check(data, thread_id) == TRUE)
			return (TRUE);
		end_time = get_curr_time(data->start_time, data);
	}
	return (FALSE);
}
// printf("%d last eat : %d\n", thread_id + 1, data->philo[thread_id].last_eat);
