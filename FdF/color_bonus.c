/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:10:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/08 15:28:34 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"

int	ft_color_vertical(t_pos from, t_pos to, int i, int step)
{
	int	color;
	int	gap;

	gap = (from.color - to.color) / step;
	color = from.color + gap * i;
	return (color);
}

int	ft_find_pixel_color(t_pos from, t_pos to, int i, int step)
{
	double	slope;
	int		color;
	int		gap;

	gap = abs((from.color - to.color) / step);
	slope = (to.y - from.y) / (to.x - from.x);
	if (fabs(slope) > 1)
	{
		if (from.y < to.y)
			color = from.color + gap * i;
		else
			color = to.color - gap * i;
	}
	else
	{
		if (from.x < to.x)
			color = from.color - gap * i;
		else
			color = to.color + gap * i;
	}
	return (color);
}


void	ft_color_setting(t_map *map)
{
	int		i;
	int		j;
	t_pos	*dot;

	dot = NULL;
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
			else if ((int)map->table[i][j].z > 0)
				dot->color = (int)(WHITE - (0x00FFFF) * (dot->z / map->z_max));
			else
				dot->color = (int)(WHITE - (0xFFFF00) / map->z_min * dot->z);
		}
	}
}
