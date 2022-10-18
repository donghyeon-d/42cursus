/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_draw_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:13:07 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/13 21:49:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	get_draw_texture(t_info *info, t_ray *ray)
{
	if (info->worldmap[ray->map_y][ray->map_x] == '2')
		return (info->texture[D_CLOSE]);
	if (ray->wall_side == EAST_OR_WEST)
	{
		if (info->pos_x > ray->map_x)
			return (info->texture[WEST]);
		else
			return (info->texture[EAST]);
	}
	if (info->pos_y > ray->map_y)
		return (info->texture[NORTH]);
	return (info->texture[SOUTH]);
}
