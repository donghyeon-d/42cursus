/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:17:10 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/28 19:13:42 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
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

//main.c
void	init_data(t_data *data);

//server_transmit.c
void	reverse_data(unsigned char *from, unsigned char *to);
void	receive_start(pid_t client_pid);
void	receive_check(void);
void	transmit_end(pid_t client_pid);
void	receive_character(void);

//server_signal.c
void	utf_check(unsigned char reverse_data);
void	server_siguser(int sum);
void	ft_sigaction_usr(int sig, siginfo_t *usr_info, void *v);

//util.c
char	*ft_itoa(int n);
void	ft_putnbr(int n);

#endif