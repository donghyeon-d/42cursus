/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:56:59 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 22:43:37 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "cub3d.h"

static t_list	*ft_maplist_new(char *content)
{
	t_list	*newlist;

	newlist = (t_list *)ft_malloc(sizeof(t_list));
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

static t_list	*make_map_list(int fd, char *line, t_info *info)
{
	t_list	*line_list;
	t_list	*temp;
	int		len;

	line_list = ft_maplist_new(line);
	len = ft_strlen(line) - 1;
	line_list->len = len;
	info->map_wid = len;
	while (line != NULL && line[0] != '\n')
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		temp = ft_maplist_new(line);
		ft_lstadd_back(&line_list, temp);
		len = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			len--;
		temp->len = len;
		if (info->map_wid < len)
			info->map_wid = len;
		info->map_hei++;
	}
	return (line_list);
}

static void	map_edge_valid_check(int **map, int hei, int wid)
{
	int	i;

	i = -1;
	while (++i < hei)
	{
		if ((map[i][0] != '1' && map[i][0] != ' ') || \
			(map[i][wid - 1] != '1' && map[i][wid - 1] != ' '))
			error_exit("invalid map");
		if ((map[i][0] == ' ' && map[i][1] == '0') ||
			(map[i][wid - 1] == ' ' && map[i][wid - 2] == '0'))
			error_exit("invalid map");
	}
	i = -1;
	while (++i < wid)
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') || \
			(map[hei - 1][i] != '1' && map[hei - 1][i] != ' '))
			error_exit("invalid map");
		if ((map[0][i] == ' ' && map[1][i] == '0') || \
			(map[hei - 1][i] == ' ' && map[hei - 2][i] == '0'))
			error_exit("invalid map");
	}
}

static void map_valid_check(int **map, int hei, int wid)
{
    int i;
    int j;
    if (hei < 3 || wid < 3)
        error_exit("Too small map");
    map_edge_valid_check(map, hei, wid);
    i = 0;
    while (++i < hei - 2)
    {
        j = 0;
        while (++j < wid - 2)
        {
			if (map[i][j] == ' ')
            {
                if ((map[i][j + 1] != '1' && map[i][j + 1] != ' ') || \
                    (map[i][j - 1] != '1' && map[i][j - 1] != ' ') || \
                    (map[i + 1][j] != '1' && map[i + 1][j] != ' ') || \
                    (map[i - 1][j] != '1' && map[i - 1][j] != ' '))
					error_exit("invalid map");
            }
        }
    }
}

void	get_map(int fd, char *line, t_info *info)
{
	t_list	*line_list;
	t_list	*temp;
	int		i;
	int		j;

	line_list = make_map_list(fd, line, info);
	temp = line_list;
	i = -1;
	info->worldmap = ft_malloc(info->map_hei * sizeof(int *));
	while (++i < info->map_hei)
	{
		j = -1;
		info->worldmap[i] = ft_malloc(info->map_wid * sizeof(int));
		while (++j < info->map_wid)
		{
			if (j < temp->len)
				info->worldmap[i][j] = ((char *)temp->content)[j];
			else
				info->worldmap[i][j] = ' ';
		}
		temp = temp->next;
	}
	map_valid_check(info->worldmap, info->map_hei, info->map_wid);
	ft_lstclear(&line_list, free);
}
