/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:37:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/05 18:21:07 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"

void	ft_double_to_int(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x = (int)map->table[i][j].x;
			map->table[i][j].y = (int)map->table[i][j].y;
		}
	}
}

// static void	ft_dot_multiple(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < data->map->height)
// 	{
// 		j = -1;
// 		while (++j < data->map->width)
// 		{
// 			data->map->table[i][j].x *= 30;
// 			data->map->table[i][j].y *= 30;
// 		}
// 	}
// }

void	ft_adj_map(t_data *data)
{
	ft_make_map_table(data->map, data->map->read_list);
	// display_map(data->map);
	// display_map(data->map);
	ft_adj_map_altitude(data);
	ft_adj_map_rotate(data->map, data->env);
	// display_map(data->map);

	// ft_dot_multiple(data);
	ft_adj_map_zoom(data);
	// display_map(data->map);
	// ft_adj_map_offset(data);
	ft_double_to_int(data->map);
	// display_map(data->map);
}