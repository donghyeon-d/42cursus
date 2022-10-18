/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cub3d_bonus.h"

static void	ft_key_rotate_clock(t_info *info)
{
	double	x;
	double	plane_x;

	x = info->dir_x;
	plane_x = info->plane_x;
	info->dir_x = x * cos(info->rot_speed) - \
					info->dir_y * sin(info->rot_speed);
	info->dir_y = info->dir_y * cos(info->rot_speed) + \
					x * sin(info->rot_speed);
	info->plane_x = info->plane_x * cos(info->rot_speed) - \
					info->plane_y * sin(info->rot_speed);
	info->plane_y = plane_x * sin(info->rot_speed) + \
					info->plane_y * cos(info->rot_speed);
}

static void	ft_key_rotate_rclock(t_info *info)
{
	double	x;
	double	plane_x;

	x = info->dir_x;
	plane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(info->rot_speed) + \
					info->dir_y * sin(info->rot_speed);
	info->dir_y = info->dir_y * cos(info->rot_speed) - \
					x * sin(info->rot_speed);
	info->plane_x = info->plane_x * cos(info->rot_speed) + \
					info->plane_y * sin(info->rot_speed);
	info->plane_y = info->plane_y * cos(info->rot_speed) - \
					plane_x * sin(info->rot_speed);
}

void	ft_key_rotate(int key, t_info *info)
{
	if (info->start_dir == 'N' || info->start_dir == 'E')
	{
		if (key == K_AR_L)
			ft_key_rotate_rclock(info);
		else if (key == K_AR_R)
			ft_key_rotate_clock(info);
	}
	else if (info->start_dir == 'S' || info->start_dir == 'W')
	{
		if (key == K_AR_R)
			ft_key_rotate_rclock(info);
		else if (key == K_AR_L)
			ft_key_rotate_clock(info);
	}
	ft_raycasting(info);
}
