/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:24:40 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 16:24:40 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*philo_main(t_data *data, int num)
{
	while (data->philo[num].status != die && data->end == FALSE)
	{
		usleep(50);
		get_forks(data, num);
		start_eating(data, num);
		putdown_forks(data, num);
		start_sleeping(data, num);
		start_thinking(data, num);
		if (data->must_eat == data->philo[num].eat_cnt)
			break ;
	}
	exit(0);
}
