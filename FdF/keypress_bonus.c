/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/07 21:40:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf_bonus.h"

void	ft_key_init(int key, t_data *data)
{
	if (key == KEY_ENTER || key == KEY_I)
	{
		data->map->offset_x = 0;
		data->map->offset_y = 0;
		data->map->x_min = IMG_WID;
		data->map->x_max = 0;
		data->map->y_min = IMG_HEI;
		data->map->y_max = 0;
		free(data->env);
		data->env = ft_init_env();
	}
	else
		return ;
	ft_handle_map(data);
}

void	ft_key_mode(int key, t_data *data)
{
	if (key == KEY_O)
	{
		data->env->alpha = 0;
		data->env->beta = 0;
		data->env->gamma = 0;
		data->env->alt = 1;
		data->env->zoom = 50;
	}
	else if (key == KEY_P)
	{
		data->env->alpha = -M_PI / 2;
		data->env->beta = 0;
		data->env->gamma = 0;
		data->env->alt = 0.3;
		data->env->zoom = 50;
	}
	ft_handle_map(data);
}

int	ft_key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_Z || key == KEY_X || key == KEY_C || \
	key == KEY_A || key == KEY_S || key == KEY_D)
		ft_key_rotate(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		ft_key_zoom(key, data);
	else if (key == KEY_UP || key == KEY_DOWN || \
	key == KEY_LEFT || key == KEY_RIGHT)
		ft_key_offset(key, data);
	else if (key == KEY_P || key == KEY_O)
		ft_key_mode(key, data);
	else if (key == KEY_ENTER || key == KEY_I)
		ft_key_init(key, data);
	else if (key == KEY_Q || key == KEY_W)
		ft_key_altitude(key, data);
	return (1);
}

int	ft_close_win(void)
{
	exit(0);
	return (0);
}
