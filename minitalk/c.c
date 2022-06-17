#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef struct s_data {
	unsigned char	client_data;
	unsigned char	reverse_data;
	int				bit_cnt;
	int				utf_byte;
	char			buf[4];
	int				buf_cnt;
} t_data;

void	init_data(t_data *data)
{
	int i = 0;

	data->client_data = 0;
	data->reverse_data = 0;
	data->bit_cnt = 0;
	data->utf_byte = 1;
	data->buf_cnt = 0;
	while (i < 4)
	{
		data->buf[i] = 0;
		i++;
	}
}


t_data get;

void alarmHandler()
{
	printf("get up!!\n");
	// exit(0);
}
void reverse_data(unsigned char *from, unsigned char *to)
{
	unsigned char temp = *from;
	for (int i = 0; i < 8; i++)
	{
		if (temp % 2 == 1)
			*to = (*to << 1) + 1;
		else if (temp % 2 == 0)
			*to = (*to << 1);
		temp /= 2;
	}
}

void convert_2base(char *from, char *to)
{
	// int f = *from;
	// int t = *to;

	for (int i = 0; i < 8; i++)
	{
		if (*from % 2 == 1)
			*to = (*to << 1) + 1;
		else if (*from % 2 == 0)
			*to = (*to << 1);
		*from /= 2;
	}
}




int main(int argc, char *argv[])
{
	init_data(&get);
	get.buf[0] = 'a';
	printf("%d\n", get.buf[0]);
	init_data(&get);
	// get.buf[0] = 'a';
	printf("%d\n", get.buf[0]);
}