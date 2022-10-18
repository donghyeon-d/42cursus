/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:08:13 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/13 19:33:53 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_position(t_info *info, int x, int y)
{
	info->pos_x = x;
	info->pos_y = y;
}

static void	get_player_dir(t_info *info, int x, int y)
{
	if (info->worldmap[y][x] == 'N')
	{
		info->dir_x = 0;
		info->dir_y = 1;
	}
	else if (info->worldmap[y][x] == 'E')
	{
		info->dir_x = -1;
		info->dir_y = 0;
	}
	else if (info->worldmap[y][x] == 'S')
	{
		info->dir_x = 0;
		info->dir_y = -1;
	}
	else if (info->worldmap[y][x] == 'W')
	{
		info->dir_x = 1;
		info->dir_y = 0;
	}
}

static void	get_player_plane(t_info *info)
{
	if (info->dir_x != 0)
	{
		info->plane_x = 0;
		info->plane_y = 0.66;
	}
	else if (info->dir_y != 0)
	{
		info->plane_x = 0.66;
		info->plane_y = 0;
	}
}

static void	get_player_info(t_info *info, int x, int y)
{
	if (info->pos_x != 0 || info->pos_y != 0)
		error_exit("Too many player");
	info->start_dir = info->worldmap[y][x];
	get_player_position(info, x, y);
	get_player_dir(info, x, y);
	get_player_plane(info);
}

void	get_player(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->map_hei)
	{
		x = -1;
		while (++x < info->map_wid)
		{
			if (info->worldmap[y][x] == 'N' || info->worldmap[y][x] == 'E' || \
			info->worldmap[y][x] == 'S' || info->worldmap[y][x] == 'W' )
				get_player_info(info, x, y);
		}
	}
	if (info->pos_x == 0 || info->pos_y == 0)
		error_exit("No player");
	info->pos_x += 0.5;
	info->pos_y += 0.5;
	info->worldmap[(int)info->pos_y][(int)info->pos_x] = '0';
}
