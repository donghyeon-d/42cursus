/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:47:46 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_door(t_info *info, t_list *door_list, int x, int y)
{
	t_img	tex;
	t_door	*door;
	int		tex_y;
	int		color;

	while (door_list)
	{
		door = door_list->content;
		if (door->wall_start <= y && y <= door->wall_end)
		{
			tex = door->texture;
			tex_y = (int)door->tex_start & (tex.hei - 1);
			door->tex_start += door->step;
			color = tex.addr[tex.wid * tex_y + door->tex_x];
			if (color != C_EMPTY)
				info->screen_img.addr[y * WIN_WID + x] = color;
		}
		door_list = door_list->next;
	}
}

static void	draw_start(t_info *info, t_ray *ray, t_draw draw, int x)
{
	int		y;

	y = -1;
	while (++y < WIN_HEI)
	{
		if (y < ray->wall_start)
			info->screen_img.addr[y * WIN_WID + x] = info->ceiling_color;
		else if (y <= ray->wall_end)
		{
			draw.tex_y = (int)draw.tex_pos & (draw.texture.hei - 1);
			draw.tex_pos += draw.step;
			info->screen_img.addr[y * WIN_WID + x] = \
				draw.texture.addr[draw.texture.wid * draw.tex_y + draw.tex_x];
		}
		else
			info->screen_img.addr[y * WIN_WID + x] = info->floor_color;
		if (ray->door_lst)
			draw_door(info, ray->door_lst, x, y);
	}
}

void	draw_line(t_info *info, t_ray *ray, int x)
{
	t_draw	draw;

	draw.texture = get_draw_texture(info, ray);
	draw.tex_x = get_texture_point_x(info, ray, draw.texture);
	draw.step = 1.0 * draw.texture.hei / ray->wall_height;
	draw.tex_pos = \
		(ray->wall_start - WIN_HEI / 2 + ray->wall_height / 2) * draw.step;
	draw_start(info, ray, draw, WIN_WID - x - 1);
}
