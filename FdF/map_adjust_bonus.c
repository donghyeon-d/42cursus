/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:37:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/01 15:28:35 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_double_to_int(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (i < map->height)
	{
		j = -1;
		while (j < map->width)
		{
			map->table[i][j].x = (int)map->table[i][j].x;
			map->table[i][j].y = (int)map->table[i][j].y;
		}
	}
}

void	ft_adj_map(t_data *data)
{
	ft_draw_background(data);
	ft_adj_map_rotate(data->map, data->env);
	ft_adj_map_altitude(data);
	ft_adj_map_zoom(data);
	ft_adj_map_offset(data);
	ft_double_to_int(data->map);
}