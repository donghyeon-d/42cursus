/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:42:25 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/13 21:08:30 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	init_step_and_sidedist(t_info *info, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (info->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - info->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (info->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - info->pos_y) * ray->deltadist_y;
	}
}

void	init_ray(t_info *info, t_ray *ray, int x)
{
	ray->carmera_x = 2 * x / (double)WIN_WID - 1;
	ray->raydir_x = info->dir_x + info->plane_x * ray->carmera_x;
	ray->raydir_y = info->dir_y + info->plane_y * ray->carmera_x;
	ray->map_x = info->pos_x;
	ray->map_y = info->pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->door_lst = NULL;
	init_step_and_sidedist(info, ray);
}
