/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:05:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 17:19:44 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_nl
{
	char				*content;
	ssize_t				fd;
	struct s_list_nl	*next;
	struct s_list_nl	*next_fd;
}	t_list_nl;

char		*ft_strldup(char *s1, ssize_t n);
t_list_nl	*ft_lstnew(char *content);
void		ft_lstadd_back(t_list_nl **lst, t_list_nl *new);
t_list_nl	*ft_lstinit(t_list_nl **head, int fd);
void		ft_clear(t_list_nl **head, int fd);
int			ft_lstsplit(t_list_nl *fd_text);
void		ft_read_addlst(t_list_nl *fd_text, int fd);
ssize_t		ft_strsize(t_list_nl *fd_text);
char		*ft_lstjoin(t_list_nl *fd_text);
char		*get_next_line(int fd);

#endif
