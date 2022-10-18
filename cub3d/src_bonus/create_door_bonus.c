/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:42:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:29:08 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

static int	get_door_texture_point_x(t_info *info, t_door *door)
{
	double	wall_x;
	int		tex_x;

	if (door->wall_side == EAST_OR_WEST)
		wall_x = info->pos_y + door->wall_dist * info->ray.raydir_y;
	else
		wall_x = info->pos_x + door->wall_dist * info->ray.raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)door->texture.wid);
	return (tex_x);
}

static void	init_door_texture_info(t_info *info, t_door *door)
{
	int		status;

	status = info->worldmap[door->map_y][door->map_x] + 2 - '0';
	door->texture = info->texture[status];
	door->tex_x = get_door_texture_point_x(info, door);
	door->step = 1.0 * door->texture.hei / door->wall_height;
	door->tex_start = \
		(door->wall_start - WIN_HEI / 2 + door->wall_height / 2) * door->step;
}

static double	calculate_door_distance(t_info *info, t_ray *ray, t_door *door)
{
	double	result;

	if (door->wall_side == EAST_OR_WEST)
		result = \
			(door->map_x - info->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		result = \
			(door->map_y - info->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
	return (result);
}

static void	init_ray_info_to_door(t_info *info, t_ray *ray, t_door *door)
{
	door->map_x = ray->map_x;
	door->map_y = ray->map_y;
	door->wall_side = ray->wall_side;
	door->wall_dist = calculate_door_distance(info, ray, door);
	door->wall_height = WIN_HEI / door->wall_dist;
	door->wall_start = -door->wall_height / 2 + WIN_HEI / 2;
	if (door->wall_start < 0)
		door->wall_start = 0;
	door->wall_end = door->wall_height / 2 + WIN_HEI / 2;
	if (door->wall_end >= WIN_HEI)
		door->wall_end = WIN_HEI - 1;
}

void	create_door(t_info *info, t_ray *ray)
{
	t_door	*door;

	door = ft_malloc(sizeof(t_door));
	ft_door_new(ray, door);
	init_ray_info_to_door(info, ray, door);
	init_door_texture_info(info, door);
}
