/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:01 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:04:01 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	die_check(t_data *data, int thread_id)
{
	if (data->end == TRUE)
		return (TRUE);
	usleep(100);
	data->time = get_curr_time(data->start_time);
	if (data->time - data->philo[thread_id].last_eat > data->time_to_die)
	{
		usleep(100);
		if (data->end != TRUE)
			print_status(data, die, thread_id);
		data->philo->status = die;
		data->end = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
