/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_offset_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:29:52 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/08 15:30:16 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_adj_mid(t_data *data)
{
	ft_find_xy_max_min(data->map);
	data->map->mid_x = (IMG_WID - data->map->x_max) / 2;
	data->map->mid_y = (IMG_HEI - data->map->y_max) / 2;
}

static void	ft_dot_add_offset(t_data *data, char x, double offset)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (x == 'x')
				data->map->table[i][j].x += offset;
			else if (x == 'y')
				data->map->table[i][j].y += offset;
			else
				exit(1);
		}
	}
}

void	ft_adj_map_offset(t_data *data)
{
	ft_adj_mid(data);
	ft_dot_add_offset(data, 'x', data->map->mid_x);
	ft_dot_add_offset(data, 'y', data->map->mid_y);
	ft_dot_add_offset(data, 'x', data->map->offset_x);
	ft_dot_add_offset(data, 'y', data->map->offset_y);
}
