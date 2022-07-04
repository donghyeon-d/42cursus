/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:37:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/04 21:51:51 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_double_to_int(t_map *map)
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

void	ft_adj_map(t_data *data)
{
	// ft_draw_background(data);
	// display_map(data->map);
	// printf("\n\n");
	ft_adj_map_rotate(data->map, data->env);
	// display_map(data->map);
	// printf("\n\n");
	ft_adj_map_altitude(data);
	// display_map(data->map);
	// printf("\n\n");
	ft_adj_map_zoom(data);
	// display_map(data->map);
	// printf("\n\n");
	ft_adj_map_offset(data);
	display_map(data->map);
	printf("\n\n");
	ft_double_to_int(data->map);
	printf("%.2f, %.2f, %.2f\n", data->env->alpha, data->env->beta, data->env->gamma);
}