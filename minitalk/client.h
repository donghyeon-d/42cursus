/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:09:06 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/18 15:36:29 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define START_OF_HEADING 1
# define END_OF_TEXT 3
# define END_OF_TRANSMISSION 4
# include <signal.h>

typedef struct s_data
{
	unsigned char	client_data;
	unsigned char	reverse_data;
	int				bit_cnt;
	int				utf_byte;
	char			buf[4];
	int				buf_cnt;
	int				transmit_cnt;
}	t_data;

t_data	g_get;

void	client_siguser(int sig);
void	transmit_text(pid_t server_pid, char *text);
void	transmit_contol(pid_t server_pid, char control);
char	*ft_itoa(int n);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

#endif