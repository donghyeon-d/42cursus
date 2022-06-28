/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:05:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/28 13:47:20 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

typedef struct s_gnl_list
{
	char			*content;
	ssize_t			fd;
	struct s_gnl_list	*next;
	struct s_gnl_list	*next_fd;
}	t_gnl_list;

char	*ft_strldup(char *s1, ssize_t n);
t_gnl_list	*ft_gnl_lstnew(char *content);
void	ft_gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new);
t_gnl_list	*ft_gnl_lstinit(t_gnl_list **head, int fd);
void	ft_clear(t_gnl_list **head, int fd);
int		ft_gnl_lstsplit(t_gnl_list *fd_text);
void	ft_read_addlst(t_gnl_list *fd_text, int fd);
ssize_t	ft_strsize(t_gnl_list *fd_text);
char	*ft_gnl_lstjoin(t_gnl_list *fd_text);
char	*get_next_line(int fd);

#endif
