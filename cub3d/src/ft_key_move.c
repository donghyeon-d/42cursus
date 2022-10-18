/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:57:33 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 12:37:36 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cub3d.h"

static void	start_dda_collision(t_ray *ray, int **worldmap)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->wall_side = EAST_OR_WEST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->wall_side = NORTH_OR_SOUTH;
		}
		if (worldmap[ray->map_y][ray->map_x] > '0' && \
		worldmap[ray->map_y][ray->map_x] != '8')
			hit = TRUE;
	}
}

static void	ft_move_back(t_info *info, int key)
{
	if (key == K_W)
	{
		info->pos_x -= info->dir_x * info->move_speed * 2;
		info->pos_y -= info->dir_y * info->move_speed * 2;
	}
	else if (key == K_S)
	{
		info->pos_x += info->dir_x * info->move_speed * 2;
		info->pos_y += info->dir_y * info->move_speed * 2;
	}
	else if (key == K_A)
	{
		info->pos_x -= info->plane_x * info->move_speed * 2;
		info->pos_y -= info->plane_y * info->move_speed * 2;
	}
	else if (key == K_D)
	{
		info->pos_x += info->plane_x * info->move_speed * 2;
		info->pos_y += info->plane_y * info->move_speed * 2;
	}
}

void	ft_rotate_clock(t_info *info, double angle)
{
	double	dir_x;
	double	plane_x;

	dir_x = info->dir_x;
	plane_x = info->plane_x;
	info->dir_x = dir_x * cos(angle) - info->dir_y * sin(angle);
	info->dir_y = info->dir_y * cos(angle) + dir_x * sin(angle);
	info->plane_x = fabs(plane_x * cos(angle) - info->plane_y * sin(angle));
	info->plane_y = fabs(info->plane_y * cos(angle) + plane_x * sin(angle));
}

static void	ft_collision_check(t_info *info, int key)
{
	t_info	move;
	t_info	min;
	int		i;

	if (info->pos_x < 1 || info->pos_y < 1 || \
		info->pos_x > info->map_wid - 1 || info->pos_y > info->map_hei - 1)
		return (ft_move_back(info, key));
	move = *info;
	min.ray.wall_dist = 1;
	i = -1;
	while (++i < 8)
	{
		init_ray(&move, &(move.ray), WIN_WID / 2);
		start_dda_collision(&(move.ray), move.worldmap);
		take_wall_point(&move, &(move.ray));
		ft_rotate_clock(&move, M_PI / 8 * (i + 1));
		if (min.ray.wall_dist > move.ray.wall_dist)
			min = move;
	}
	if (min.ray.wall_dist < 0.2 || \
	info->worldmap[(int)info->pos_y][(int)info->pos_x] == 1)
		ft_move_back(info, key);
}

void	ft_key_move(int key, t_info *info)
{
	if (key == K_W)
	{
		info->pos_x += info->dir_x * info->move_speed;
		info->pos_y += info->dir_y * info->move_speed;
	}
	else if (key == K_S)
	{
		info->pos_x -= info->dir_x * info->move_speed;
		info->pos_y -= info->dir_y * info->move_speed;
	}
	else if (key == K_A)
	{
		info->pos_x += info->plane_x * info->move_speed;
		info->pos_y += info->plane_y * info->move_speed;
	}
	else if (key == K_D)
	{
		info->pos_x -= info->plane_x * info->move_speed;
		info->pos_y -= info->plane_y * info->move_speed;
	}
	ft_collision_check(info, key);
	ft_raycasting(info);
}
