/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:31:35 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	map_edge_valid_check(int **map, int hei, int wid)
{
	int	i;

	i = -1;
	while (++i < hei)
	{
		if ((map[i][0] != '1' && map[i][0] != ' ') || \
			(map[i][wid - 1] != '1' && map[i][wid - 1] != ' '))
			error_exit("invalid map(side edge)");
		if ((map[i][0] == ' ' && map[i][1] == '0') ||
			(map[i][wid - 1] == ' ' && map[i][wid - 2] == '0'))
			error_exit("invalid map(side edge)");
	}
	i = -1;
	while (++i < wid)
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') || \
			(map[hei - 1][i] != '1' && map[hei - 1][i] != ' '))
			error_exit("invalid map(layer edge)");
		if ((map[0][i] == ' ' && map[1][i] == '0') || \
			(map[hei - 1][i] == ' ' && map[hei - 2][i] == '0'))
			error_exit("invalid map(layer edge)");
	}
}

static void	map_space_vaild_check(int **map, int x, int y)
{
	if ((map[y][x + 1] != '1' && map[y][x + 1] != ' ') || \
		(map[y][x - 1] != '1' && map[y][x - 1] != ' ') || \
		(map[y + 1][x] != '1' && map[y + 1][x] != ' ') || \
		(map[y - 1][x] != '1' && map[y - 1][x] != ' '))
		error_exit("invalid map(space)");
}

static void	map_door_vaild_check(int **map, int x, int y)
{
	if (!(((map[y][x - 1] == '1' && map[y][x + 1] == '1') && \
		(map[y - 1][x] != '1' && map[y + 1][x] != '1')) || \
		((map[y][x - 1] != '1' && map[y][x + 1] != '1') && \
		(map[y - 1][x] == '1' && map[y + 1][x] == '1'))))
		error_exit("door must between walls");
}

void	map_valid_check(int **map, int hei, int wid)
{
	int	x;
	int	y;

	if (hei < 3 || wid < 3)
		error_exit("Too small map");
	map_edge_valid_check(map, hei, wid);
	y = 0;
	while (++y < hei - 1)
	{
		x = 0;
		while (++x < wid - 1)
		{
			if (map[y][x] == ' ')
				map_space_vaild_check(map, x, y);
			else if (map[y][x] == '2' || map[y][x] == '8')
				map_door_vaild_check(map, x, y);
			else if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'N' \
			|| map[y][x] == 'E' || map[y][x] == 'S' || map[y][x] == 'W')
				continue ;
			else
				error_exit("Wrong map point value");
		}
	}
}
