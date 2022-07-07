/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitude_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:13 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 17:08:49 by dongchoi         ###   ########.fr       */
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
			data->map->table[i][j].z *= data->env->alt;
	}
}
