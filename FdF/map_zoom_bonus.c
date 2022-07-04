/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zoom_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:03:30 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/04 21:39:49 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_dot_add_min(t_data *data, char x, double min)
{
	int	i;
	int	j;

	i = -1;
	if (min < 0)
	{
		min *= -1;
		while (++i < data->map->height)
		{
			j = -1;
			while (++j < data->map->width)
			{
				if (x == 'x')
					data->map->table[i][j].x += min;
				else if (x == 'y')
					data->map->table[i][j].y += min;
				else
					exit(1);
			}
		}
		if (x == 'x')
			data->map->x_max += min;
		else if (x == 'y')
			data->map->y_max += min;
	}
}

static void ft_adj_zoomsize(t_data *data)
{
	if (IMG_WID < data->map->x_max * data->env->zoom)
		data->env->zoom = IMG_WID / data->map->x_max;
	if (IMG_HEI < data->map->y_max * data->env->zoom)
		data->env->zoom = IMG_WID / data->map->y_max;
}

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
	data->map->x_max *= zoom;
	data->map->y_max *= zoom;
}

void	ft_adj_map_zoom(t_data *data)
{
	ft_dot_add_min(data, 'x', data->map->x_min);
	ft_dot_add_min(data, 'y', data->map->y_min);
	ft_adj_zoomsize(data);
	ft_dot_multiple_zoom(data, data->env->zoom);
}