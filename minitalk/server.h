
#ifndef SERVER_H
#define SERVER_H
#define START_OF_HEADING 1
#define END_OF_TEXT 3
#define END_OF_TRANSMISSION 4

#include <signal.h>

typedef struct s_data {
	unsigned char	client_data;
	unsigned char	reverse_data;
	int				bit_cnt;
	int				utf_byte;
	char			buf[4];
	int				buf_cnt;
	int             transmit_cnt;
} t_data;

t_data get;

void	init_data(t_data *data);

void	receive_start(pid_t client_pid);
void	reverse_data(unsigned char *from, unsigned char *to);
void	receive_check();
void	transmit_end(pid_t client_pid);
void	receive_character();

void	utf_check(unsigned char reverse_data);
void	server_siguser(int sum);
void	ft_sigaction_usr(int sig, siginfo_t *usr_info, void *v);

//utils.c
char	*ft_itoa(int n);
void	ft_putnbr(int n);

#endif