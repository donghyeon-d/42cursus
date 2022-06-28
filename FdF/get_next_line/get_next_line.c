/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:48:22 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/28 13:54:34 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnl_lstsplit(t_gnl_list *fd_text)
{
	ssize_t	i;
	ssize_t	len;
	char	*str;

	str = fd_text->content;
	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		ft_gnl_lstadd_back(&fd_text, ft_gnl_lstnew(ft_strldup(str, i + 1)));
		fd_text->content = ft_strldup(&(str[i + 1]), len - i - 1);
		free(str);
		return (0);
	}
	else
	{
		ft_gnl_lstadd_back(&fd_text, ft_gnl_lstnew(ft_strldup(str, len)));
		fd_text->content = NULL;
	}
	free(str);
	return (1);
}

void	ft_read_addlst(t_gnl_list *fd_text, int fd)
{
	char	*str;
	ssize_t	i;
	ssize_t	temp;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (str == NULL)
		return ;
	temp = read(fd, str, BUFFER_SIZE);
	while (temp > 0)
	{
		str[temp] = '\0';
		i = 0;
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			ft_gnl_lstadd_back(&fd_text, ft_gnl_lstnew(ft_strldup(str, i + 1)));
			fd_text->content = ft_strldup(&(str[i + 1]), temp - i - 1);
			free(str);
			return ;
		}
		ft_gnl_lstadd_back(&fd_text, ft_gnl_lstnew(ft_strldup(str, i + 1)));
		temp = read(fd, str, BUFFER_SIZE);
	}
	free(str);
}

ssize_t	ft_strsize(t_gnl_list *fd_text)
{
	t_gnl_list	*temp;
	ssize_t	size;
	ssize_t	i;

	temp = fd_text;
	size = 0;
	while (temp)
	{
		i = 0;
		while ((temp->content)[i])
		{
			i++;
			size++;
		}
		temp = temp->next;
	}
	return (size);
}

char	*ft_gnl_lstjoin(t_gnl_list *fd_text)
{
	char	*result;
	t_gnl_list	*temp;
	ssize_t	i;
	ssize_t	j;
	ssize_t	size;

	temp = fd_text->next;
	size = ft_strsize(temp);
	if (size == 0)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (temp)
	{
		j = 0;
		while ((temp->content)[j])
			result[i++] = (temp->content)[j++];
		temp = temp->next;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*fd_text;
	char			*result;
	ssize_t			content_end;

	content_end = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (head == NULL)
		head = ft_gnl_lstnew(NULL);
	if (head != NULL)
		fd_text = ft_gnl_lstinit(&head, fd);
	if (head == NULL || fd_text == NULL)
		return (NULL);
	if (fd_text->content != NULL)
		content_end = ft_gnl_lstsplit(fd_text);
	if (fd_text->content == NULL && content_end == 1)
		ft_read_addlst(fd_text, fd);
	result = ft_gnl_lstjoin(fd_text);
	if (fd_text->next != NULL)
		ft_clear(&(fd_text->next), -1);
	fd_text->next = NULL;
	if (result == NULL)
		ft_clear(&head, fd);
	return (result);
}
