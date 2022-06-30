/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:48:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 11:35:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "./ft_libft/libft.h"

void	ft_rotate_x(t_pos *dot, t_env *env)
{
	double	prev_y;

	prev_y = dot->y;
	dot->y = prev_y * cos(env->alpha) + (dot->z) * sin(env->alpha);
	dot->z = -prev_y * sin(env->alpha) + (dot->z) * cos(env->alpha);
	if (dot->x < env->x_min)
		env->x_min = dot->x;
	if (dot->y < env->y_min)
		env->y_min = dot->y;
}

void	ft_rotate_matrix_clockwise(t_pos *dot, t_env *env)
{
	double	x;
	double	y;

	x = dot->x;
	y = dot->y;
	dot->x = (x * cos(env->angle_radian) - y * sin(env->angle_radian));
	dot->y = (y * cos(env->angle_radian) + x * sin(env->angle_radian));
	dot->x *= env->distance;
	dot->y *= env->distance;
	if (dot->x < env->x_min)
		env->x_min = dot->x;
	if (dot->y < env->y_min)
		env->y_min = dot->y;
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
			ft_rotate_matrix_clockwise(&(map->table[i][j]), env);
			ft_add_altitude(&(map->table[i][j]), env);
			ft_rotate_x(&(map->table[i][j]), env);
		}
	}
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x += (env->x_min * -1);
			map->table[i][j].y += (env->y_min * -1);
		}
	}
}
