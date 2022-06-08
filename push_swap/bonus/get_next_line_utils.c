/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:48:38 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 17:21:35 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strldup(char *s1, ssize_t n)
{
	int		i;
	char	*result;

	if (n == 0 && s1[0] == '\0')
		return (NULL);
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_list_nl	*ft_lstnew(char *content)
{
	t_list_nl	*newlist;

	newlist = (t_list_nl *)malloc(sizeof(t_list_nl));
	if (newlist == NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	newlist->next_fd = NULL;
	newlist->fd = -1;
	return (newlist);
}

void	ft_lstadd_back(t_list_nl **lst, t_list_nl *new)
{
	t_list_nl	*temp;

	if (new == NULL)
		return ;
	if (new->content == NULL)
	{
		free(new);
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_list_nl	*ft_lstinit(t_list_nl **head, int fd)
{
	t_list_nl	*fd_text;
	t_list_nl	*start;

	if (fd < 0)
		return (NULL);
	start = *head;
	fd_text = ft_lstnew(NULL);
	if (fd_text == NULL)
		return (NULL);
	while (start->fd != fd)
	{
		if (start->next_fd == NULL)
		{
			start->next_fd = fd_text;
			fd_text->fd = fd;
			return (fd_text);
		}
		else
			start = start->next_fd;
	}
	free(fd_text);
	return (start);
}

void	ft_clear(t_list_nl **head, int fd)
{
	t_list_nl	*del;
	t_list_nl	*temp;

	temp = *head;
	while (temp && fd < 0)
	{
		del = temp;
		temp = temp->next;
		free(del->content);
		free(del);
	}
	while (temp && temp->next_fd->fd != fd && fd >= 0)
		temp = temp->next_fd;
	if (temp && temp->next_fd->fd == fd && fd >= 0)
	{
		del = temp->next_fd;
		temp->next_fd = del->next_fd;
		free(del);
	}
	if (((*head)->next_fd) == NULL && fd >= 0)
	{
		free(*head);
		*head = NULL;
	}
}
