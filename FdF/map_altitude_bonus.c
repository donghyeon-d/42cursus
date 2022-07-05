/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitude_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:13 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/05 18:24:40 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

// static void	ft_dot_add_z_to_y(t_map *map, double altitude)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < map->height)
// 	{
// 		j = -1;
// 		while (++j < map->width)
// 		{
// 			map->table[i][j].y += map->table[i][j].z * altitude;
// 			if (map->y_max < map->table[i][j].y)
// 				map->y_max = map->table[i][j].y;
// 			if (map->y_min > map->table[i][j].y)
// 				map->y_min = map->table[i][j].y;
// 		}
// 	}
// }

void	ft_adj_map_altitude(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			data->map->table[i][j].y += data->env->alt;
			// if (data->map->y_max < data->map->table[i][j].y)
			// 	data->map->y_max = data->map->table[i][j].y;
			// if (data->map->y_min > data->map->table[i][j].y)
			// 	data->map->y_min = data->map->table[i][j].y;
		}
	}
	printf("%.2f\n", data->env->alt);
		display_map(data->map);
}
// {
// 	ft_dot_add_z_to_y(data->map, 1);
// 	if (data->map->y_max * data->env->alt * data->env->zoom > IMG_HEI)
// 		data->env->alt = IMG_HEI / data->map->y_max / data->map->height;
// 	ft_dot_add_z_to_y(data->map, -1);
// 	ft_dot_add_z_to_y(data->map, data->env->alt * -1);


// 	// display_map(data->map);
// 	// ft_find_min_edge(data->map);
// 	// ft_adj_edge(data->map, data->map->x_min * -1, 0);
// 	ft_adj_edge(data->map, 0, data->map->y_min * -1);
// 	data->map->x_min = IMG_WID;
// 	data->map->y_min = IMG_HEI;
// 	// display_map(data->map);
// }