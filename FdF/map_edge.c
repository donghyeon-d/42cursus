/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:11:11 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 10:40:41 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"

void	ft_find_min_edge(t_map *map)
{
	if (map->y_min > map->table[0][0].y)
		map->y_min = map->table[0][0].y;
	if (map->x_min > map->table[0][0].x)
		map->x_min = map->table[0][0].x;
	if (map->x_min > map->table[0][map->width - 1].x)
		map->x_min = map->table[0][map->width - 1].x;
	if (map->y_min > map->table[0][map->width - 1].y)
		map->y_min = map->table[0][map->width - 1].y;
	if (map->x_min > map->table[map->height - 1][0].x)
		map->x_min = map->table[map->height - 1][0].x;
	if (map->y_min > map->table[map->height - 1][0].y)
		map->y_min = map->table[map->height - 1][0].y;
	if (map->x_min > map->table[map->height - 1][map->width - 1].x)
		map->x_min = map->table[map->height - 1][map->width - 1].x;
	if (map->y_min > map->table[map->height - 1][map->width - 1].y)
		map->y_min = map->table[map->height - 1][map->width - 1].y;
}

void	ft_find_max_edge(t_map *map)
{
	if (map->y_min < map->table[0][0].y)
		map->y_min = map->table[0][0].y;
	if (map->x_min < map->table[0][0].x)
		map->x_min = map->table[0][0].x;
	if (map->x_min < map->table[0][map->width - 1].x)
		map->x_min = map->table[0][map->width - 1].x;
	if (map->y_min < map->table[0][map->width - 1].y)
		map->y_min = map->table[0][map->width - 1].y;
	if (map->x_min < map->table[map->height - 1][0].x)
		map->x_min = map->table[map->height - 1][0].x;
	if (map->y_min < map->table[map->height - 1][0].y)
		map->y_min = map->table[map->height - 1][0].y;
	if (map->x_min < map->table[map->height - 1][map->width - 1].x)
		map->x_min = map->table[map->height - 1][map->width - 1].x;
	if (map->y_min < map->table[map->height - 1][map->width - 1].y)
		map->y_min = map->table[map->height - 1][map->width - 1].y;
}

void	ft_find_max_min(t_map *map)
{
	int	i;
	int	j;

	map->x_min = IMG_WID;
	map->y_min = IMG_HEI;
	map->x_max = -1;
	map->y_max = -1;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->x_max < map->table[i][j].x)
				map->x_max = map->table[i][j].x;
			if (map->y_max < map->table[i][j].y)
				map->y_max = map->table[i][j].y;
			if (map->x_min > map->table[i][j].x)
				map->x_min = map->table[i][j].x;
			if (map->y_min > map->table[i][j].y)
				map->y_min = map->table[i][j].y;
		}
	}
}

void	ft_adj_edge(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = -1;
	// ft_find_min_edge(map);
	// ft_find_max_edge(map);
	// printf("\nft_adj_edge, (x)%.2f, (y)%.2f\n", x, y);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x += x;
			map->table[i][j].y += y;
			// printf("%.2f %.2f %.2f\n", map->table[i][j].x, map->table[i][j].y, map->table[i][j].z);
		}
	}
}