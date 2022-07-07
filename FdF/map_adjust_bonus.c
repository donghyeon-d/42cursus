/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:37:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/07 21:39:32 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "fdf_bonus.h"

void	ft_string_put(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 50, 80, 0xFFFFFFF, "    [KEY]");
	mlx_string_put(data->mlx, data->win, 50, 120, 0xFFFFFFF, "--- ROTATE ---");
	mlx_string_put(data->mlx, data->win, 50, 140, 0xFFFFFFF, "Z : rotate x++");
	mlx_string_put(data->mlx, data->win, 50, 160, 0xFFFFFFF, "X : rotate y++");
	mlx_string_put(data->mlx, data->win, 50, 180, 0xFFFFFFF, "C : rotate z++");
	mlx_string_put(data->mlx, data->win, 50, 200, 0xFFFFFFF, "A : rotate x--");
	mlx_string_put(data->mlx, data->win, 50, 220, 0xFFFFFFF, "S : rotate y--");
	mlx_string_put(data->mlx, data->win, 50, 240, 0xFFFFFFF, "D : rotate z--");
	mlx_string_put(data->mlx, data->win, 50, 300, 0xFFFFFFF, "--- ZOOM ---");
	mlx_string_put(data->mlx, data->win, 50, 320, 0xFFFFFFF, "+ : zoom in");
	mlx_string_put(data->mlx, data->win, 50, 340, 0xFFFFFFF, "- : zoom out");
	mlx_string_put(data->mlx, data->win, 50, 400, 0xFFFFFFF, "--- INIT ---");
	mlx_string_put(data->mlx, data->win, 50, 420, 0xFFFFFFF, "I : initialization");
	mlx_string_put(data->mlx, data->win, 50, 440, 0xFFFFFFF, "O : upside");
	mlx_string_put(data->mlx, data->win, 50, 460, 0xFFFFFFF, "P : parallel");
	mlx_string_put(data->mlx, data->win, 50, 520, 0xFFFFFFF, "--- ALTITUDE ---");
	mlx_string_put(data->mlx, data->win, 50, 540, 0xFFFFFFF, "Q : altitude++");
	mlx_string_put(data->mlx, data->win, 50, 560, 0xFFFFFFF, "W : altitude--");
	mlx_string_put(data->mlx, data->win, 50, 620, 0xFFFFFFF, "--- OFFSET ---");
	mlx_string_put(data->mlx, data->win, 50, 640, 0xFFFFFFF, "UP : offset_y++");
	mlx_string_put(data->mlx, data->win, 50, 660, 0xFFFFFFF, "DOWN : offset_y--");
	mlx_string_put(data->mlx, data->win, 50, 680, 0xFFFFFFF, "LEFT : offset_x--");
	mlx_string_put(data->mlx, data->win, 50, 700, 0xFFFFFFF, "RGHT : offset_x++");
}

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
	// ft_map_clear(data->map);
	ft_make_map_table(data->map, data->map->read_list);
	ft_adj_map_altitude(data);
	ft_color_setting(data->map);
	ft_adj_map_rotate(data->map, data->env);
	ft_adj_map_zoom(data);
	ft_adj_map_offset(data);
	ft_find_max_min(data->map);
	ft_double_to_int(data->map);
}

void	ft_handle_map(t_data *data)
{
	ft_adj_map(data);
	ft_draw_background(data);
	ft_draw_line_all(data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_string_put(data);
	// system("leaks fdf_bonus");
}

// void	ft_map_clear(t_map *map)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < map->height)
// 		free(map->table[i]);
// 	free(map->table);
// }