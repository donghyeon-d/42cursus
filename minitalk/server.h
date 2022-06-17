
#ifndef SERVER_H
#define SERVER_H

#include <signal.h>

typedef struct s_data {
	unsigned char	client_data;
	unsigned char	reverse_data;
	int				bit_cnt;
	int				utf_byte;
	char			buf[4];
	int				buf_cnt;
} t_data;

t_data get;

void	init_data(t_data *data);
void	utf_check(unsigned char reverse_data);
void	reverse_data(unsigned char *from, unsigned char *to);
void	ft_sigaction_usr1(int sig, siginfo_t *usr1_info, void *v);
void	ft_sigaction_usr2(int sig, siginfo_t *usr2_info, void *v);


#endif