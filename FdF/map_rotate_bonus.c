/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:48:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/01 14:34:34 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_rotate_x(t_pos *dot, t_env *env)
{
	double	prev_y;

	prev_y = dot->y;
	dot->y = prev_y * cos(env->alpha) + (dot->z) * sin(env->alpha);
	dot->z = -prev_y * sin(env->alpha) + (dot->z) * cos(env->alpha);
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
			ft_rotate_x(&(map->table[i][j]), env);
			ft_rotate_y(&(map->table[i][j]), env, map);
			ft_rotate_z(&(map->table[i][j]), env, map);
		}
	}
}
