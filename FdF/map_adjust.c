/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:37:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/09 16:27:06 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20210621/mlx.h"
#include "fdf.h"

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

void	ft_adj_map(t_data *data)
{
	ft_make_map_table(data->map, data->map->read_list);
	ft_adj_map_altitude(data);
	ft_color_setting(data->map);
	ft_adj_map_rotate(data->map, data->env);
	ft_adj_map_zoom(data);
	ft_adj_map_offset(data);
	ft_find_xy_max_min(data->map);
	ft_double_to_int(data->map);
}

void	ft_handle_map(t_data *data)
{
	ft_adj_map(data);
	ft_draw_background(data);
	ft_draw_line_all(data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_string_put(data);
}

void	ft_draw_background(t_data *data)
{
	int	i;

	i = -1;
	while (++i < IMG_HEI * IMG_WID)
		data->ad[i] = BLACK;
}

void	ft_adj_dot_xy(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x += x;
			map->table[i][j].y += y;
		}
	}
}
