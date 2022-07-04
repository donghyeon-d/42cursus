/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitude_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:13 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/04 21:21:54 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static double	ft_dot_add_z_to_y(t_map *map, double altitude)
{
	int	i;
	int	j;
	double	max;

	i = -1;
	max = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].y += map->table[i][j].z * altitude;
			if (max < map->table[i][j].y)
				max = map->table[i][j].y;
		}
	}
	return (max);
}

void	ft_adj_map_altitude(t_data *data)
{
	data->map->y_max = ft_dot_add_z_to_y(data->map, 1);
	if (data->map->y_max * data->env->alt * data->env->zoom > IMG_HEI)
		data->env->alt = IMG_HEI / data->map->y_max / data->map->height;
	data->map->y_max = ft_dot_add_z_to_y(data->map, -1);
	data->map->y_max = ft_dot_add_z_to_y(data->map, data->env->alt);
}