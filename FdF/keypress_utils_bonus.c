/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/07 19:08:36 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

void	ft_key_offset(int key, t_data *data)
{
	ft_find_max_min(data->map);
	if (key == KEY_UP)
	{
		if (data->map->y_max + data->map->offset_y > 0)
			data->map->offset_y -= 30;
	}
	else if (key == KEY_DOWN)
	{
		if (data->map->y_min + data->map->offset_y < IMG_HEI)
			data->map->offset_y += 30;
	}
	else if (key == KEY_LEFT)
	{
		if (data->map->x_max + data->map->offset_x > 0)
			data->map->offset_x -= 30;
	}
	else if (key == KEY_RIGHT)
	{
		if (data->map->x_min + data->map->offset_x < IMG_WID)
		data->map->offset_x += 30;
	}
	else
		return ;
	ft_handle_map(data);
}

void	ft_key_altitude(int key, t_data *data)
{
	if (key == KEY_Q)
		data->env->alt += 0.1;
	else if (key == KEY_W)
		data->env->alt -= 0.1;
	ft_adj_map(data);
	if (data->map->y_max > IMG_HEI || data->map->y_min < 0)
	{
		if (data->env->alt > 0)
			data->env->alt -= 0.1;
		else
			data->env->alt += 0.1;
	}
	ft_handle_map(data);
}

void	ft_key_zoom(int key, t_data *data)
{
	double	wid;
	double	hei;

	wid = data->map->x_max / data->env->zoom;
	hei = data->map->y_max / data->env->zoom;
	if (key == KEY_PLUS)
	{
		if (IMG_WID * 2 >= wid * (data->env->zoom + 5) && \
		IMG_HEI * 2 >= hei * (data->env->zoom + 5))
			data->env->zoom += 5;
	}
	else if (key == KEY_MINUS)
	{
		data->env->zoom -= 5;
		if (data->env->zoom < 10)
			data->env->zoom += 5;
	}
	ft_handle_map(data);
}

void	ft_key_rotate(int key, t_data *data)
{
	if (key == KEY_Z)
		data->env->alpha += 0.05;
	else if (key == KEY_A)
		data->env->alpha -= 0.05;
	else if (key == KEY_X)
		data->env->beta += 0.05;
	else if (key == KEY_S)
		data->env->beta -= 0.05;
	else if (key == KEY_C)
		data->env->gamma += 0.05;
	else if (key == KEY_D)
		data->env->gamma -= 0.05;
	ft_handle_map(data);
}
