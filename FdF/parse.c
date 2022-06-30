/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:45:26 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 11:29:39 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "fdf.h"
#include "./ft_libft/libft.h"

void	ft_free_double(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

t_map	*ft_init_map(int height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	map->height = height;
	map->width = 0;
	map->distance = 10;
	map->table = ft_calloc(map->height, sizeof(t_pos *));
	if (map->table == NULL)
		exit(1);
	return (map);
}

int	ft_map_valid_check(t_map *map, t_list *read_list)
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
	if (count % map->width != 0 || count % map->height != 0)
		return (FALSE);
	return (TRUE);
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

t_map	*make_map(char *map_file)
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
	ft_map_valid_check(map, read_list);
	ft_make_map_table(map, read_list);
	ft_lstclear(&read_list, free);
	return (map);
}
