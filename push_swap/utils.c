#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long	ft_atoll(char *argv)
{
	long long	num;
	int			i;

	num = 0;
	i = ft_strlen(argv);
	while (--i >= 0 && ft_isdigit(argv[i]))
		num = num * 10 + argv[i] - '0';
	if (i == 0 && argv[i] == '-')
		num *= -1;
	if (i > 0 || !ft_isdigit(argv[i]))
		num = LLONG_MAX;
	return (num);
}