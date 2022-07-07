/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 15:06:02 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "fdf_bonus.h"

// void display_map(t_map *map)
// {
// 	for (int i = 0; i < map->height; i++)
// 	{
// 		for (int j = 0; j < map->width; j++)
// 			printf("{%.2f %.2f %.2f} ", map->table[i][j].x, map->table[i][j].y, map->table[i][j].z);
// 		printf("\n");
// 	}
// }

void	ft_key_offset(int key, t_data *data)
{
	if (key == KEY_UP)
	{
		data->map->offset_y -= 5;
		if (data->map->offset_y > IMG_HEI / 2)
		{
			data->map->offset_y += 5;
		}
	}
	else if (key == KEY_DOWN)
	{
		data->map->offset_y += 5;
		if (data->map->offset_y < -1 * IMG_HEI / 2)
		{
			data->map->offset_y -= 5;
		}
	}
	else if (key == KEY_LEFT)
	{
		data->map->offset_x -= 5;
		if (data->map->offset_x < -1 * IMG_WID / 2)
		{
			data->map->offset_y += 5;
		}
	}
	else if (key == KEY_RIGHT)
	{
		data->map->offset_x += 5;
		if (data->map->offset_y > IMG_HEI / 2)
		{
			data->map->offset_x -= 5;
		}
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
		data->env->alpha += 0.03;
	else if (key == KEY_A)
		data->env->alpha -= 0.03;
	else if (key == KEY_X)
		data->env->beta += 0.03;
	else if (key == KEY_S)
		data->env->beta -= 0.03;
	else if (key == KEY_C)
		data->env->gamma += 0.03;
	else if (key == KEY_D)
		data->env->gamma -= 0.03;
	ft_handle_map(data);
}

void	ft_key_init(int key, t_data *data)
{
	if (key == KEY_ENTER)
	{
		free(data->map);
		data->map = make_map(data->map_file);
		free(data->env);
		data->env = ft_init_env();
	}
	else
		return ;
	ft_handle_map(data);
}

void	ft_key_mode(int key, t_data *data)
{
	if (key == KEY_P)
	{
		data->env->alpha = 0;
		data->env->beta = 0;
		data->env->gamma = 0;
		data->env->alt = 1;
		data->env->zoom = 50;
	}
	else if (key == KEY_I)
	{
		free(data->map);
		data->map = make_map(data->map_file);
		free(data->env);
		data->env = ft_init_env();
	}
	ft_handle_map(data);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_Z || key == KEY_X || key == KEY_C || \
	key == KEY_A || key == KEY_S || key == KEY_D)
		ft_key_rotate(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		ft_key_zoom(key, data);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		ft_key_offset(key, data);
	else if (key == KEY_P || key == KEY_I)
		ft_key_mode(key, data);
	// else if (key == KEY_P || key == KEY_I)
	// 	ft_key_iso(key, data);
	else if (key == KEY_ENTER)
		ft_key_init(key, data);
	else if (key == KEY_Q || key == KEY_W)
		ft_key_altitude(key, data);
	return (1);
}

int	ft_close_win(void *param)
{
	exit(0);
	param = (char *)0;
}
