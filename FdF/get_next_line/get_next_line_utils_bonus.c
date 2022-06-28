/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:57:28 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/30 12:05:20 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_list	*ft_lstnew(char *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	newlist->next_fd = NULL;
	newlist->fd = -1;
	return (newlist);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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

t_list	*ft_lstinit(t_list **head, int fd)
{
	t_list	*fd_text;
	t_list	*start;

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

void	ft_clear(t_list **head, int fd)
{
	t_list	*del;
	t_list	*temp;

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
