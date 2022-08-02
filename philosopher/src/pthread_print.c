/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:07 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:04:07 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_status(t_data *data, t_status status, int thread_id)
{
	data->time = get_curr_time(data->start_time);
	if (status == -1)
		printf("%d %d is died\n", data->time, thread_id + 1);
	else if (status == 0)
		printf("%d %d is sleeping\n", data->time, thread_id + 1);
	else if (status == 1)
		printf("%d %d is thinking\n", data->time, thread_id + 1);
	else if (status == 2)
		printf("%d %d has taken a fork\n", data->time, thread_id + 1);
	else if (status == 3)
		printf("%d %d is eating\n", data->time, thread_id + 1);
	else
		printf("printf Error\n");
}
