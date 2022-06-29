#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include "c.h"

int	ft_round_off(double num)
{
	if (num > 0)
	{
		if ((num - (int)num) < 0.5)
		return ((int)num);
	return ((int)num + 1);
	}
	else
	{
		if((num + (int)num) < -0.5)
			return ((int)num - 1);
		return ((int)num);
	}
}

void	ft_draw_vertical(t_data *img, t_pos from, t_pos to)
{
	int		step;
	int		pixel;
	int		i;

	step = (to.y - from.y);
	i = -1;
	pixel = from.x + IMG_WIDTH * from.y;
	while (++i < step)
	{
		pixel += IMG_WIDTH;
		// pixel += from.x + IMG_WIDTH * (from.y + i);
		img->addr[pixel] = 0xFFFFFF;
	}
}

void	ft_draw_line(t_data *img, t_pos from, t_pos to)
{
	double	slope;
	int		step;
	int		pixel;
	int		i;

	if (to.x - from.x != 0)
	{
		slope = (double)(to.y - from.y) / (to.x - from.x);
		if (fabs((double)slope) > 1)
		{
			step = (int)fabs((double)to.y - from.y);
			i = -1;
			slope = (double)(to.x - from.x) / (to.y - from.y);
			while (++i < step)
			{
				pixel = IMG_WIDTH * (from.y + i) + from.x + ft_round_off(i * slope);
				img->addr[pixel] = 0xFFFFFF;
			}	
		}
		else
		{
			step = (int)fabs((double)to.x - from.x);
			pixel = from.x + IMG_WIDTH * from.y;
			img->addr[pixel] = 0xFFFFFF;
			i = -1;
			if (to.x > from.x)
			{
				while (++i < step)
				{
					pixel = (from.x + i) + IMG_WIDTH * (from.y + ft_round_off(i * slope));
					img->addr[pixel] = 0xFFFFFF;
				}
			}
			else
			{
				while (++i < step)
				{
					pixel = (to.x + i) + IMG_WIDTH * (to.y + ft_round_off(i * slope));
					img->addr[pixel] = 0xFFFFFF;
				}
			}
		}
	}
	else
		ft_draw_vertical(img, from, to);
}

void	ft_draw_line_all(t_map *map, t_data *img)
{
	int	i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j + 1 < map->width)
				ft_draw_line(img, map->map_table[i][j], map->map_table[i][j + 1]);
			if (i + 1 < map->height)
				ft_draw_line(img, map->map_table[i][j], map->map_table[i + 1][j]);
		}
	}
}
// void	ft_draw_line(t_data *img, t_pos from, t_pos to, int distance)
// {
// 	int		pixel;
// 	double	y;
// 	double	z;
// 	double	i;
// 	int		inc;

// 	// inc = (to.y - from.y) / (to.x - from.x);
// 	if (to.x - to.y == 0)
// 		inc = 0;
// 	else
// 		inc = (to.y - from.y) / (to.x - from.x);
// 	i = (int)(sqrt(pow(to.x, 2) + pow(from.x, 2)));
// 	pixel = from.x + from.y * IMG_WIDTH;
// 	while (i--)
// 	{
// 		img->addr[pixel] = 0xFFFFFF;
// 		pixel++;
// 		to.x++;
// 		if (to.x % inc)
// 	}


// 	x = from.x - 1;
// 	y = from.y - 1;
// 	while (++x < to.x * distance)
// 	{
// 		img->addr[x] = 0xFFFFFF;
// 		i = - 1;
// 		// while (++i < distance)
// 	}

// }