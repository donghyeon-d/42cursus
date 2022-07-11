/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_minmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:11:11 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/09 16:19:50 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	ft_find_xy_max_min(t_map *map)
{
	int	i;
	int	j;

	map->x_min = IMG_WID;
	map->y_min = IMG_HEI;
	map->x_max = -1;
	map->y_max = -1;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->x_max < map->table[i][j].x)
				map->x_max = map->table[i][j].x;
			if (map->y_max < map->table[i][j].y)
				map->y_max = map->table[i][j].y;
			if (map->x_min > map->table[i][j].x)
				map->x_min = map->table[i][j].x;
			if (map->y_min > map->table[i][j].y)
				map->y_min = map->table[i][j].y;
		}
	}
}

void	ft_find_z_max_min(t_map *map)
{
	int	i;
	int	j;

	map->z_max = -1;
	map->z_min = 2147483647;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->z_max < map->table[i][j].z)
				map->z_max = map->table[i][j].z;
			if (map->z_min > map->table[i][j].z)
				map->z_min = map->table[i][j].z;
		}
	}
}
