/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:56:52 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 13:56:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include "mlx.h"

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
		if (worldmap[ray->map_y][ray->map_x] > '0')
			hit = TRUE;
	}
}

static void	ft_door_close(t_info *info, t_info move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		info->worldmap[move.ray.map_y][move.ray.map_x]--;
		ft_raycasting(info);
		j = -1;
		while (++j < 30)
			mlx_do_sync(info->mlx);
	}
}

static void	ft_door_open(t_info *info, t_info move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		info->worldmap[move.ray.map_y][move.ray.map_x]++;
		ft_raycasting(info);
		j = -1;
		while (++j < 30)
			mlx_do_sync(info->mlx);
	}
}

static void	ft_is_near_door(t_info *info)
{
	t_info	move;

	move = *info;
	init_ray(&move, &(move.ray), WIN_WID / 2);
	start_dda_collision(&(move.ray), move.worldmap);
	take_wall_point(&move, &(move.ray));
	if (move.ray.wall_dist < 0.2 || 1.0 <= move.ray.wall_dist)
		return ;
	if (info->worldmap[move.ray.map_y][move.ray.map_x] == '8')
		ft_door_close(info, move);
	else if (info->worldmap[move.ray.map_y][move.ray.map_x] == '2')
		ft_door_open(info, move);
}

void	ft_door_control(t_info *info)
{
	ft_is_near_door(info);
}
