/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:05:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/30 12:10:45 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	ssize_t			fd;
	struct s_list	*next;
	struct s_list	*next_fd;
}	t_list;

char	*ft_strldup(char *s1, ssize_t n);
t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstinit(t_list **head, int fd);
void	ft_clear(t_list **head, int fd);
int		ft_lstsplit(t_list *fd_text);
void	ft_read_addlst(t_list *fd_text, int fd);
ssize_t	ft_strsize(t_list *fd_text);
char	*ft_lstjoin(t_list *fd_text);
char	*get_next_line(int fd);

#endif
