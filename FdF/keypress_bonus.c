/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 19:03:59 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "fdf_bonus.h"

void display_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("{%.2f %.2f %.2f} ", map->table[i][j].x, map->table[i][j].y, map->table[i][j].z);
		printf("\n");
	}
}

int	key_press(int keycode, t_data *img)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Z)
	{
		ft_draw_line_all(img->map, img, 0x000000);
		img->env->distance += 1;
		// mlx_destroy_image(img->mlx, img->img);
		// img->img = mlx_new_image(img->mlx, IMG_WID, IMG_HEI);
		// img->ad = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
		free(img->map);
		img->map = make_map(img->map_file);
		ft_rotate_map(img->map, img->env);
		display_map(img->map);
		ft_draw_line_all(img->map, img, 0xFFFFFF);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	}
	else if (keycode == KEY_X)
	{
		ft_draw_line_all(img->map, img, 0x000000);
		img->env->distance -= 1;
		// mlx_destroy_image(img->mlx, img->img);
		// img->img = mlx_new_image(img->mlx, IMG_WID, IMG_HEI);
		// img->ad = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
		free(img->map);
		img->map = make_map(img->map_file);
		ft_rotate_map(img->map, img->env);
		display_map(img->map);
		ft_draw_line_all(img->map, img,0xFFFFFF);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	}
	return (1);
}

int	ft_close_win(void *param)
{
	exit(0);
	param = (char *)0;
}
