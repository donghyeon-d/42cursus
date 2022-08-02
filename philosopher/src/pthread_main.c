/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:04:04 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:04:04 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*pthread_main(void *data)
{
	t_data		*d;
	int			id;

	d = (t_data *)data;
	id = d->t_id;
	while (d->end == FALSE)
	{
		usleep(30);
		get_forks(d, id);
		start_eating(d, id);
		putdown_forks(d, id);
		start_sleeping(d, id);
		start_thinking(d, id);
		if (d->must_eat == d->philo[id].eat_cnt)
			break ;
	}
	return (0);
}
