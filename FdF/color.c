/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:10:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/09 16:19:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

int	ft_color_vertical(t_pos from, t_pos to, int i, int step)
{
	int	color;
	int	gap;

	if (from.color > to.color)
	{
		gap = (from.color - to.color) / step;
		color = from.color - gap * i;
	}
	else
	{
		gap = (to.color - from.color) / step;
		color = from.color + gap * i;
	}
	return (color);
}

static int	ft_find_pixel_color_steep(t_pos from, t_pos to, int i, int gap)
{
	int	color;

	if (from.y < to.y)
	{
		if (from.color > to.color)
			color = from.color - gap * i;
		else
			color = from.color + gap * i;
	}
	else
	{
		if (from.color > to.color)
			color = to.color + gap * i;
		else
			color = to.color - gap * i;
	}
	return (color);
}

static int	ft_find_pixel_color_gentle(t_pos from, t_pos to, int i, int gap)
{
	int	color;

	if (from.x < to.x)
	{
		if (from.color > to.color)
			color = from.color - gap * i;
		else
			color = from.color + gap * i;
	}
	else
	{
		if (from.color > to.color)
			color = to.color + gap * i;
		else
			color = to.color - gap * i;
	}
	return (color);
}

int	ft_find_pixel_color(t_pos from, t_pos to, int i, int step)
{
	double	slope;
	int		color;
	int		gap;

	slope = fabs((to.y - from.y) / (to.x - from.x));
	gap = fabs((double)(from.color - to.color) / step);
	if (slope > 1)
		color = ft_find_pixel_color_steep(from, to, i, gap);
	else
		color = ft_find_pixel_color_gentle(from, to, i, gap);
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
