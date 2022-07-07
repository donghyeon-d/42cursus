/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:35:06 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/07 20:21:06 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"

static int	ft_round_off(double num)
{
	if (num > 0)
	{
		if ((num - (int)num) < 0.5)
			return ((int)num);
		return ((int)num + 1);
	}
	else
	{
		if ((num + (int)num) < -0.5)
			return ((int)num - 1);
		return ((int)num);
	}
}

void	ft_draw_vertical(t_data *img, t_pos from, t_pos to)
{
	int		step;
	int		pixel;
	int		i;

	i = -1;
	if (from.y < to.y)
	{
		step = (int)(to.y - from.y);
		pixel = from.x + IMG_WID * from.y;
	}
	else
	{
		step = (int)(from.y - to.y);
		pixel = to.x + IMG_WID * to.y;
	}
	while (++i < step)
	{
		pixel += IMG_WID;
		if (pixel >= 0 && pixel <= IMG_HEI * IMG_WID)
			img->ad[pixel] = ft_color_vertical(from, to, i, step);
	}
}

int	ft_find_pixel_point(t_pos from, t_pos to, int i)
{
	double	slope;
	int		p;

	slope = (to.y - from.y) / (to.x - from.x);
	if (to.x > IMG_WID || from.x > IMG_WID || to.x < 0 || from.x < 0)
		return (-1);
	if (fabs(slope) > 1)
	{
		slope = (to.x - from.x) / (to.y - from.y);
		if (from.y < to.y)
			p = IMG_WID * ((int)from.y + i) + from.x + ft_round_off(i * slope);
		else
			p = IMG_WID * ((int)to.y + i) + to.x + ft_round_off(i * slope);
	}
	else
	{
		if (from.x < to.x)
			p = from.x + i + IMG_WID * ((int)from.y + ft_round_off(i * slope));
		else
			p = to.x + i + IMG_WID * ((int)to.y + ft_round_off(i * slope));
	}
	return (p);
}

void	ft_draw_line(t_data *data, t_pos from, t_pos to)
{
	double	slope;
	int		step;
	int		pixel;
	int		i;
	int		color;

	if (to.x - from.x != 0)
	{
		slope = (to.y - from.y) / (to.x - from.x);
		if (fabs(slope) > 1)
			step = (int)fabs((double)to.y - from.y);
		else
			step = (int)fabs((double)to.x - from.x);
		i = -1;
		while (++i < step)
		{
			color = ft_find_pixel_color(from, to, i, step);
			pixel = ft_find_pixel_point(from, to, i);
			if (pixel >= 0 && pixel <= IMG_HEI * IMG_WID)
				data->ad[pixel] = color;
		}
	}
	else
		ft_draw_vertical(data, from, to);
}

void	ft_draw_line_all(t_data *img, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j + 1 < map->width)
				ft_draw_line(img, map->table[i][j], map->table[i][j + 1]);
			if (i + 1 < map->height)
				ft_draw_line(img, map->table[i][j], map->table[i + 1][j]);
		}
	}
}
