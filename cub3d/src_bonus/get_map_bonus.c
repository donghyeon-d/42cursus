/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:56:59 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_list	*ft_maplist_new(char *content)
{
	t_list	*newlist;

	newlist = (t_list *)ft_malloc(sizeof(t_list));
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

static t_list	*make_map_list(int fd, char **line, t_info *info)
{
	t_list	*line_list;
	t_list	*temp;
	int		len;

	line_list = ft_maplist_new(*line);
	len = ft_strlen(*line) - 1;
	line_list->len = len;
	info->map_wid = len;
	while (*line != NULL && *line[0] != '\n')
	{
		*line = get_next_line(fd);
		if (*line == NULL || *line[0] == '\n')
			break ;
		temp = ft_maplist_new(*line);
		ft_lstadd_back(&line_list, temp);
		len = ft_strlen(*line);
		if (ft_strchr(*line, '\n'))
			len--;
		temp->len = len;
		if (info->map_wid < len)
			info->map_wid = len;
		info->map_hei++;
	}
	return (line_list);
}

void	get_map(int fd, char **line, t_info *info)
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
