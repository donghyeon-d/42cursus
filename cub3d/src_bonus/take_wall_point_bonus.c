/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_wall_point_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:20:01 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calculate_distance(t_info *info, t_ray *ray)
{
	if (ray->wall_side == EAST_OR_WEST)
		ray->wall_dist = \
			(ray->map_x - info->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->wall_dist = \
			(ray->map_y - info->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
}

void	take_wall_point(t_info *info, t_ray *ray)
{
	calculate_distance(info, ray);
	ray->wall_height = WIN_HEI / ray->wall_dist;
	ray->wall_start = -ray->wall_height / 2 + WIN_HEI / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + WIN_HEI / 2;
	if (ray->wall_end >= WIN_HEI)
		ray->wall_end = WIN_HEI - 1;
}
