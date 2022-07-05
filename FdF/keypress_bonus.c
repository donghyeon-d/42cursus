/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/05 18:20:23 by dongchoi         ###   ########.fr       */
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
		data->map->offset_y += 0.1;
		if (data->map->offset_y > IMG_HEI / 2)
		{
			//글씨 출력해보자	(못 올림)print : you can't add offset_y
			data->map->offset_y -= 0.1;
		}
	}
	else if (key == KEY_DOWN)
	{
		data->map->offset_y -= 0.1;
		if (data->map->offset_y < -1 * IMG_HEI / 2)
		{
			//글씨 출력해보자	(못 올림)print : you can't add offset_y
			data->map->offset_y += 0.1;
		}
	}
	else if (key == KEY_LEFT)
	{
		data->map->offset_x -= 0.1;
		if (data->map->offset_x < -1 * IMG_WID / 2)
		{
			//글씨 출력해보자	(못 올림)print : you can't add offset_y
			data->map->offset_y += 0.1;
		}
	}
	else if (key == KEY_RIGHT)
	{
		data->map->offset_y += 0.1;
		if (data->map->offset_y > IMG_HEI / 2)
		{
			//글씨 출력해보자	(못 올림)print : you can't add offset_y
			data->map->offset_y -= 0.1;
		}
	}
	else
		return ;
	ft_handle_map(data);
}

void	ft_key_altitude(int key, t_data *data)
{
	if (key == KEY_Q)
	{
		data->env->alt += 0.1;
		// if (IMG_HEI < data->map->y_max * data->env->zoom * data->env->alt)
		// {
		// 	//글씨 출력해보자	(못 올림)print : you can't add height
		// 	data->env->alt -= 0.1;
		// }
	}
	else if (key == KEY_W)
	{
		data->env->alt -= 0.1;
		// if (data->env->alt < 0.1)
		// {
		// 	//글씨 출력해보자 (못 내림)
		// 	data->env->alt += 0.1;
		// }
	}
	else
		return ;
	// ft_make_map_table(data->map, data->map->read_list);
	
	ft_handle_map(data);
}

void	ft_key_zoom(int key, t_data *data)
{
	if (key == KEY_PLUS)
	{
		data->env->zoom += 0.1;
		// if (IMG_WID < data->map->x_max * data->env->zoom || \
		// IMG_HEI < data->map->y_max * data->env->zoom)
		// {
		// 	data->env->zoom -= 0.1;
		// 	//글씨 출력해보자 
		// }
	}
	else if (key == KEY_MINUS)
	{
		data->env->zoom -= 0.1;
		// if (data->env->zoom < 10)
		// {
		// 	data->env->zoom += 0.1;
		// 	//글씨 출력해보자
		// }
	}
	else
		return ;
	ft_handle_map(data);
}

void	ft_key_rotate(int key, t_data *data)// 계속 증가한다면 어떻게 되지?
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
	else
		return ;
	// ft_adj_map_rotate(data->map, data->env);
	// ft_adj_map_altitude(data);
	// ft_adj_map_zoom(data);
	// ft_double_to_int(data->map);
	// ft_draw_background(data);
	// ft_draw_line_all(data, data->map, WHITE);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_Z || key == KEY_X || key == KEY_C || \
	key == KEY_A || key == KEY_S || key == KEY_D)
		ft_key_rotate(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		ft_key_zoom(key, data);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_DOWN)
		ft_key_offset(key, data);
	// else if (key == KEY_O || key == KEY_I)
	// 	ft_key_iso(key, data);
	else if (key == KEY_ENTER)
		ft_key_init(key, data);
	else if (key == KEY_Q || key == KEY_W)
		ft_key_altitude(key, data);
	else
		return (0);
	return (1);
}

int	ft_close_win(void *param)
{
	exit(0);
	param = (char *)0;
}
