/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_point_x_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:13:37 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

int	get_texture_point_x(t_info *info, t_ray *ray, t_img texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->wall_side == EAST_OR_WEST)
		wall_x = info->pos_y + ray->wall_dist * ray->raydir_y;
	else
		wall_x = info->pos_x + ray->wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture.wid);
	if (ray->wall_side == EAST_OR_WEST && ray->raydir_x > 0)
		tex_x = texture.wid - tex_x - 1;
	if (ray->wall_side == NORTH_OR_SOUTH && ray->raydir_y < 0)
		tex_x = texture.wid - tex_x - 1;
	if (info->start_dir == 'N' || info->start_dir == 'E')
		tex_x = texture.wid - tex_x - 1;
	return (tex_x);
}
