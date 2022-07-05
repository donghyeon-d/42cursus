/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:48:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/05 18:28:05 by dongchoi         ###   ########.fr       */
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
	display_map(map);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			ft_rotate_x(&(map->table[i][j]), env, map);
			ft_rotate_y(&(map->table[i][j]), env, map);
			ft_rotate_z(&(map->table[i][j]), env, map);
		}
	}
	ft_find_max_min(map);
	ft_adj_edge(map, map->x_min * -1, 0);
	// if (map->x_min < 0)
	// 	ft_adj_edge(map, map->x_min * -1, 0);
	// else if (map->x_min > 0)
	// 	ft_adj_edge(map, map->x_min * -1, 0);
	
	// printf("min : %.2f %.2f", map->x_min, map->y_min);
	// if (map->y_min < 0)
	// 	ft_adj_edge(map, 0, map->y_min * -1);
	// else if (map->y_min > 0)
	ft_adj_edge(map, 0, map->y_min * -1);
	display_map(map);
	// map->x_min = IMG_WID;
	// map->y_min = IMG_HEI;
}
