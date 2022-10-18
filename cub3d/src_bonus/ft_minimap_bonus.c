/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:14:27 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d_bonus.h"

static int	ft_minimap_color(t_info *info, int x, int y)
{
	int	color;

	color = 0;
	if (x < 0 || y < 0 || x > info->map_wid - 1 || y > info->map_hei - 1)
		color = C_MAP_WALL;
	else
	{
		if (info->worldmap[y][x] == '1' || info->worldmap[y][x] == ' ')
			color = C_MAP_WALL;
		else if ('1' < info->worldmap[y][x] && info->worldmap[y][x] < '9')
			color = C_MAP_DOOR;
		else if (info->worldmap[y][x] == '0')
			color = C_MAP_PATH;
		else if (info->worldmap[y][x] == 'W' || info->worldmap[y][x] == 'E' || \
		info->worldmap[y][x] == 'S' || info->worldmap[y][x] == 'N')
			color = C_MAP_PLAYER;
		if (color == info->ceiling_color || color == info->floor_color)
		{
			if (color > 0x222222)
				color -= 0x222222;
			else
				color += 0x222222;
		}
	}
	return (color);
}

static void	ft_minimap_draw_player(t_info *info)
{
	int	x;
	int	y;

	y = 96;
	while (++y < 104)
	{
		x = 96;
		while (++x < 104)
		info->minimap.addr[(199 - x) + (199 - y) * 256] = C_MAP_PLAYER;
	}
}

static void	ft_minimap_draw_all(t_info *info)
{
	double	p_x;
	double	p_y;
	int		color;
	int		x;
	int		y;

	p_x = info->pos_x - 5;
	p_y = info->pos_y - 5;
	y = -1;
	while (++y < 200)
	{
		x = -1;
		while (++x < 200)
		{
			color = ft_minimap_color(info, p_x + x * 0.05, p_y + y * 0.05);
			info->minimap.addr[(199 - x) + (199 - y) * 256] = color;
		}
	}
	ft_minimap_draw_player(info);
}

void	ft_minimap(t_info *info)
{
	int		minimap_hei;
	int		minimap_wid;

	if (info->minimap_on == FALSE)
		return ;
	minimap_hei = 10;
	minimap_wid = 10;
	info->minimap.img = mlx_new_image(info->mlx, 200, 200);
	info->minimap.addr = (int *)mlx_get_data_addr(info->minimap.img, \
	&info->minimap.bpp, &info->minimap.len, &info->minimap.end);
	ft_minimap_draw_all(info);
	mlx_put_image_to_window(info->mlx, info->win, info->minimap.img, 10, 10);
}
