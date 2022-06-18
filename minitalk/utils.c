#include <unistd.h>
#include <stdlib.h>

static int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = ft_ilen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	while (n > 0)
	{
		num[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

void	ft_putnbr(int n)
{
	char	*buf;
    int     len;

	buf = ft_itoa(n);
    len = 0;
    if (buf == NULL)
        exit(1);
    while(buf[len])
        len++;
    if (len != 0)
        write(1, buf, len);
	free(buf);
}