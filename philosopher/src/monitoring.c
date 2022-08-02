/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:34 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:03:35 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	make_monitor(t_data	*data)
{
	data->monitor = malloc(sizeof(pthread_t));
	if (data->monitor == NULL)
		return (FALSE);
	if (pthread_create(data->monitor, NULL, monitoring_main, (void *)data) != 0)
		return (FALSE);
	return (TRUE);
}

void	*monitoring_main(void	*data)
{
	t_data	*d;
	int		i;
	int		cnt;

	d = (t_data *)data;
	while (d->start == 0)
		;
	while (1)
	{
		i = -1;
		cnt = 0;
		while (++i < d->philo_cnt)
		{
			if (d->philo[i].eat_cnt == d->must_eat)
				cnt++;
			if (d->philo[i].status == die || cnt == d->philo_cnt)
			{
				d->end = TRUE;
				return (NULL);
			}
		}
	}
}
