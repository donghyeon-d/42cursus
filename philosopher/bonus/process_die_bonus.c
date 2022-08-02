/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_die_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:51:59 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:52:00 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	die_check(t_data *data, int thread_id)
{
	usleep(150);
	if (data->end == TRUE || data->philo->status == die)
		return (TRUE);
	data->time = get_curr_time(data->start_time, data);
	if (data->time - data->philo[thread_id].last_eat > data->time_to_die)
	{
		data->end = TRUE;
		data->philo->status = die;
		print_status(data, die, thread_id);
		kill(data->monitor, SIGINT);
		return (TRUE);
	}
	return (FALSE);
}
