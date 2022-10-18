/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:14:31 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cub3d_bonus.h"

void	ft_key_minimap_ctl(t_info *info)
{
	if (info->minimap_on == FALSE)
		info->minimap_on = TRUE;
	else
		info->minimap_on = FALSE;
	ft_raycasting(info);
}

void	ft_key_move_speed(int key, t_info *info)
{
	if (key == K_P && info->move_speed > 0.05)
		info->move_speed -= 0.01;
	else if (key == K_O && info->move_speed < 0.2)
		info->move_speed += 0.01;
}

int	ft_key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_A || key == K_S || key == K_D || key == K_W)
		ft_key_move(key, info);
	else if (key == K_AR_L || key == K_AR_R)
		ft_key_rotate(key, info);
	else if (key == K_P || key == K_O)
		ft_key_move_speed(key, info);
	else if (key == K_SP)
		ft_door_control(info);
	else if (key == K_TAB)
		ft_key_minimap_ctl(info);
	return (1);
}
