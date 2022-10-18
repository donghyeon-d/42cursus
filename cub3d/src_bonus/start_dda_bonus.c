/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dda_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:49:41 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	start_dda(t_info *info, t_ray *ray)
{
	int		hit;
	int		**worldmap;

	hit = FALSE;
	worldmap = info->worldmap;
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
		if (worldmap[ray->map_y][ray->map_x] > '2')
			create_door(info, ray);
		else if (worldmap[ray->map_y][ray->map_x] > '0')
			hit = TRUE;
	}
}
