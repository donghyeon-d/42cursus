/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:09 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:04:10 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_curr_time(struct timeval start_time)
{
	struct timeval	end_time;
	int				time;

	gettimeofday(&end_time, NULL);
	time = ((end_time.tv_sec * 1000000 + end_time.tv_usec) - \
			(start_time.tv_sec * 1000000 + start_time.tv_usec)) / 1000;
	return (time);
}

int	put_delay(t_data *data, int delay_time, int thread_id)
{
	int	curr_time;
	int	end_time;

	curr_time = get_curr_time(data->start_time);
	end_time = get_curr_time(data->start_time);
	while (end_time - curr_time < delay_time)
	{
		if (data->end == TRUE || die_check(data, thread_id) == TRUE)
			return (TRUE);
		end_time = get_curr_time(data->start_time);
	}
	return (FALSE);
}
