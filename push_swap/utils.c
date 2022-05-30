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
	int			len;
	int			sign;
	char		*str;

	num = 0;
	str = argv;
	len = ft_strlen(argv);
	sign = 1;
	i = 0;
	if (argv[i] == '-')
		sign *= -1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (i < len && ft_isdigit(argv[i]))
		num = num * 10 + argv[i++] - '0';
	if (i < len)
		num = LLONG_MAX;
	return (num);
}

// int main()
// {
// 	char **ar;
// 	long long digit;

// 	ar = (char **)malloc(sizeof(char *) * 5);
// 	for (int i = 0; i < 5; i++)
// 		ar[i] = (char *)malloc(sizeof(char) * 5);
// 	ar[0] = "31";
// 	ar[1] = "11";
// 	ar[2] = "21";
// 	ar[3] = "51";
// 	ar[4] = "41";

// 	for (int j; j < 5; j++)
// 	{
// 		digit = ft_atoll(&ar[j][0]);
// 		printf("%lld\n", digit);
// 	}
// 	return (0);
// }