/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:45:22 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "minishell.h"

void	wildcard_add_back(t_token_node *node, t_token_node *tmp)
{
	if (node == NULL)
		return ;
	while (node->next)
		node = node->next;
	node->next = tmp;
}

int	pattern_check(char *filename, char *wc)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (wc[++i] != '\0')
	{
		if (wc[i] == '*')
		{
			while (filename[j] != '\0' && filename[j] != wc[i + 1])
			{
				j++;
			}
		}
		else
		{
			if (wc[i] != filename[j] || filename[j] == '\0')
				return (FALSE);
			else
				j++;
		}
	}
	if (filename[j] != '\0')
		return (FALSE);
	return (TRUE);
}

t_token_node	*wc_set(t_token_node *temp, char *filename, char *wc)
{
	t_token_node	*new;
	char			*line;

	if (pattern_check(filename, wc) && filename[0] != '.')
		line = ft_strdup(filename);
	else
		return (temp);
	if (temp == NULL)
		temp = create_token_node(line);
	else
	{
		new = create_token_node(line);
		wildcard_add_back(temp, new);
	}
	return (temp);
}

t_token_node	*make_wc_list(t_token_node *node)
{
	DIR				*dir_fd;
	struct dirent	*dir_info;
	t_token_node	*temp;

	temp = NULL;
	dir_fd = opendir(".");
	if (dir_fd == NULL)
		exit (1);
	dir_info = readdir(dir_fd);
	while (dir_info)
	{
		temp = wc_set(temp, (char *)(dir_info->d_name), node->token);
		dir_info = readdir(dir_fd);
	}
	closedir(dir_fd);
	return (temp);
}
