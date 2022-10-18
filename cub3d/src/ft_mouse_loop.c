/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:20:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/13 17:20:44 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "cub3d.h"

static void	ft_mouse_rotate_clock(t_info *info)
{
	double	x;
	double	plane_x;

	x = info->dir_x;
	plane_x = info->plane_x;
	info->dir_x = x * cos(M_PI / 140) - info->dir_y * sin(M_PI / 140);
	info->dir_y = info->dir_y * cos(M_PI / 140) + x * sin(M_PI / 140);
	info->plane_x = info->plane_x * cos(M_PI / 140) - \
					info->plane_y * sin(M_PI / 140);
	info->plane_y = plane_x * sin(M_PI / 140) + \
					info->plane_y * cos(M_PI / 140);
}

static void	ft_mouse_rrotate_clock(t_info *info)
{
	double	x;
	double	plane_x;

	x = info->dir_x;
	plane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(M_PI / 140) + \
					info->dir_y * sin(M_PI / 140);
	info->dir_y = info->dir_y * cos(M_PI / 140) - x * sin(M_PI / 140);
	info->plane_x = info->plane_x * cos(M_PI / 140) + \
					info->plane_y * sin(M_PI / 140);
	info->plane_y = info->plane_y * cos(M_PI / 140) - \
					plane_x * sin(M_PI / 140);
}

static void	ft_mouse_rotate(t_info *info, int mouse_x)
{
	double	x;
	double	plane_x;

	x = info->dir_x;
	plane_x = info->plane_x;
	if (info->start_dir == 'N' || info->start_dir == 'E')
	{
		if (mouse_x < WIN_WID / 2)
			ft_mouse_rrotate_clock(info);
		else if (mouse_x > WIN_WID / 2)
			ft_mouse_rotate_clock(info);
	}
	else if (info->start_dir == 'S' || info->start_dir == 'W')
	{
		if (mouse_x > WIN_WID / 2)
			ft_mouse_rrotate_clock(info);
		else if (mouse_x < WIN_WID / 2)
			ft_mouse_rotate_clock(info);
	}
}

int	ft_mouse_loop(t_info *info)
{
	int	mouse_x;
	int	y;

	if (info->mouse_ctl == FALSE)
		return (0);
	mlx_mouse_move(info->win, WIN_WID / 2, WIN_HEI / 2);
	mlx_mouse_get_pos(info->win, &mouse_x, &y);
	if (mouse_x != WIN_WID / 2)
	{
		ft_mouse_rotate(info, mouse_x);
		ft_raycasting(info);
	}
	return (0);
}
