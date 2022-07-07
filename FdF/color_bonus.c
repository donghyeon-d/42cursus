/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:10:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 17:52:16 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"

int	ft_find_pixel_color(t_pos from, t_pos to, int i, int step)
{
	double	sl;
	int	color;
	int	gap;

	gap = (from.color - to.color) / step;
	if (to.x - from.x != 0)
		sl = (to.y - from.y) / (to.x - from.x);
	if (to.x - from.x != 0)
		color = from.color - gap * i;
	else if (fabs(sl) > 1)
	{
		sl = (to.x - from.x) / (to.y - from.y);
		if (from.y < to.y)
			color = from.color + gap * i;
		else
			color = to.color + gap * i;
	}
	else
	{
		if (from.x < to.x)
			color = from.color - gap * i;
		else
			color = to.color - gap * i;
	}
	return (color);
}

void	ft_find_z_max_min(t_map *map)
{
	int	i;
	int	j;

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

void	ft_color_setting(t_map *map)
{
	int	i;
	int	j;
	t_pos	*dot = NULL;

	ft_find_z_max_min(map);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			dot = &(map->table[i][j]);
			if ((int)map->table[i][j].z == 0)
				dot->color = WHITE;
			else// if ((int)map->table[i][j].z >= 0)
				dot->color = (int)(WHITE - (WHITE - RED) / map->z_max * dot->z);
			// else
			// 	dot->color = (int)(WHITE - (WHITE - BLUE) / map->z_min * dot->z);
		}
	}
}