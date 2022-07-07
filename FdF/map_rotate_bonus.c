/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:48:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 17:06:21 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_rotate_x(t_pos *dot, t_env *env, t_map *map)
{
	double	prev_y;

	prev_y = dot->y;
	dot->y = prev_y * cos(env->alpha) + (dot->z) * sin(env->alpha);
	dot->z = -prev_y * sin(env->alpha) + (dot->z) * cos(env->alpha);
	if (dot->y < map->y_min)
		map->y_min = dot->y;
}

static void	ft_rotate_y(t_pos *dot, t_env *env, t_map *map)
{
	double	prev_x;

	prev_x = dot->x;
	dot->x = prev_x * cos(env->beta) + (dot->z) * sin(env->beta);
	dot->z = -prev_x * sin(env->beta) + (dot->z) * cos(env->beta);
	if (dot->x < map->x_min)
		map->x_min = dot->x;
}

static void	ft_rotate_z(t_pos *dot, t_env *env, t_map *map)
{
	double	prev_x;
	double	prev_y;

	prev_x = dot->x;
	prev_y = dot->y;
	dot->x = prev_x * cos(env->gamma) - prev_y * sin(env->gamma);
	dot->y = prev_x * sin(env->gamma) + prev_y * cos(env->gamma);
	if (dot->x < map->x_min)
		map->x_min = dot->x;
	if (dot->y < map->y_min)
		map->y_min = dot->y;
}

void	ft_adj_map_rotate(t_map *map, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			// map->table[i][j].z *= env->alt;
			ft_rotate_x(&(map->table[i][j]), env, map);
			ft_rotate_y(&(map->table[i][j]), env, map);
			ft_rotate_z(&(map->table[i][j]), env, map);
		}
	}
	ft_find_max_min(map);
	ft_adj_edge(map, map->x_min * -1, 0);
	ft_adj_edge(map, 0, map->y_min * -1);
}
