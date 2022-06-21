/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:18:31 by choidongd         #+#    #+#             */
/*   Updated: 2022/06/18 15:36:11 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		len;

	buf = ft_itoa(n);
	len = 0;
	if (buf == NULL)
		exit(1);
	while (buf[len] != '\0')
		len++;
	if (len != 0)
		write(1, buf, len);
	free(buf);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ('+' == *str || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}	
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}
