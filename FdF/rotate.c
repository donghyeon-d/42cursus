#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "c.h"
#include "./ft_libft/libft.h"

void	rotate_x(t_pos *dot, double alpha)
{
	int	prev_y;

	prev_y = dot->y;
	dot->y = prev_y * cos(alpha) + (dot->z) * sin(alpha);
	dot->z = -prev_y * sin(alpha) + (dot->z) * cos(alpha);
}

void	ft_rotate_matrix_clockwise(t_pos *dot, t_env env)
{
	double	x;
	double	y;

	x = dot->x;
	y = dot->y;
	dot->x = (x * cos(env.angle_radian) - y * sin(env.angle_radian)) * env.distance;
	dot->y = (y * cos(env.angle_radian) + x * sin(env.angle_radian)) * env.distance;
}

void	ft_add_altitude(t_pos *dot, t_env *env)
{
	dot->y -= dot->z * env->altitude;
	if (dot->y < env->y_min)
		env->y_min = dot->y;
}

void	ft_rotate_map(t_map *map, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ft_rotate_matrix_clockwise(&(map->map_table[i][j]), *env);
			if (map->map_table[i][j].x < env->x_min)
				env->x_min = map->map_table[i][j].x;
			rotate_x(&(map->map_table[i][j]), -0.08);
			ft_add_altitude(&(map->map_table[i][j]), env);
		}
	}
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->map_table[i][j].x += (env->x_min * -1);
			map->map_table[i][j].y += (env->y_min * -1);
		}
	}
}