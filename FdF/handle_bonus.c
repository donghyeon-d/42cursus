/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:27:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/05 14:36:14 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf_bonus.h"

void display_map(t_map *map)
{
	printf("\n");
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("{%.2f %.2f %.2f} ", map->table[i][j].x, map->table[i][j].y, map->table[i][j].z);
		printf("\n");
	}
	printf("\n");
}

void	ft_draw_background(t_data *data)
{
	int	i;

	i = -1;
	while (++i < IMG_HEI * IMG_WID)
		data->ad[i] = 0x000000;
}

int ft_handle_map(t_data *data)
{
	ft_adj_map(data);
	ft_draw_background(data);
	ft_draw_line_all(data, data->map, WHITE);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}