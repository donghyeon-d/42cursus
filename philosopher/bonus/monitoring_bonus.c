/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:46 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 15:44:55 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	make_monitor(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		while (1)
			;
	}
	else if (pid == 0)
		data->monitor = pid;
	else
		return (FALSE);
	return (TRUE);
}
