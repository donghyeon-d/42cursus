/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zoom_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:03:30 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/08 15:31:02 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"

static void	ft_dot_multiple_zoom(t_data *data, double zoom)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			data->map->table[i][j].x *= zoom;
			data->map->table[i][j].y *= zoom;
		}
	}
}

void	ft_adj_map_zoom(t_data *data)
{
	ft_find_xy_max_min(data->map);
	if (data->env->init == 1)
	{
		if (IMG_WID < data->map->x_max * data->env->zoom)
			data->env->zoom = IMG_WID / (data->map->x_max + 1);
		if (IMG_HEI < data->map->y_max * data->env->zoom)
			data->env->zoom = IMG_HEI / (data->map->y_max + 1);
	}
	ft_dot_multiple_zoom(data, data->env->zoom);
}
