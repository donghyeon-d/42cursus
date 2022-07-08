/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:45:26 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/08 16:10:12 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

static void	ft_free_double(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

static int	ft_map_valid_check(t_map *map, t_list *read_list)
{
	int		i;
	t_list	*node;
	char	**temp;
	int		count;

	count = 0;
	node = read_list;
	while (node)
	{
		i = -1;
		temp = ft_split(node->content, ' ');
		while (temp[++i])
		{
			map->width++;
			count++;
			free(temp[i]);
		}
		free(temp);
		node = node->next;
		if (node != NULL)
			map->width = 0;
	}
	if (map->width * map->height != count || map->width < 2 || map->height < 2)
		return (FALSE);
	return (TRUE);
}

static t_map	*ft_init_map(int height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	map->height = height;
	map->table = ft_calloc(map->height, sizeof(t_pos *));
	if (map->table == NULL)
		exit(1);
	map->width = 0;
	map->offset_x = 0;
	map->offset_y = 0;
	map->x_min = IMG_WID;
	map->x_max = 0;
	map->y_min = IMG_HEI;
	map->y_max = 0;
	return (map);
}

void	ft_make_map_table(t_map	*map, t_list *read_list)
{
	char	**temp;
	t_list	*node;
	int		i;
	int		j;

	node = read_list;
	i = -1;
	while (++i < map->height)
	{
		temp = ft_split(node->content, ' ');
		j = -1;
		if (map->table[i] == NULL)
			map->table[i] = ft_calloc(map->width, sizeof(t_pos));
		if (map->table[i] == NULL)
			exit(1);
		j = -1;
		while (++j < map->width)
		{
			map->table[i][j].x = (double)j;
			map->table[i][j].y = (double)i;
			map->table[i][j].z = (double)ft_atoi(temp[j]);
		}
		node = node->next;
		ft_free_double(temp);
	}
}

t_map	*ft_make_map(char *map_file)
{
	int		fd;
	char	*read_line;
	t_map	*map;
	t_list	*read_list;

	fd = open(map_file, O_RDWR);
	read_line = get_next_line(fd);
	read_list = ft_lstnew(read_line);
	while (read_line != NULL)
	{
		read_line = get_next_line(fd);
		ft_lstadd_back(&read_list, ft_lstnew(read_line));
	}
	map = ft_init_map(ft_lstsize(read_list));
	if (ft_map_valid_check(map, read_list) == FALSE)
		exit(1);
	map->read_list = read_list;
	close(fd);
	return (map);
}
