/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:30:39 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:40:48 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "a.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] != '\0') && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if (res > LLONG_MAX + 1ULL && sign == -1)
			return (0);
		else if (res > LLONG_MAX && sign == 1)
			return (-1);
		i++;
	}
	return (sign * (int)res);
}

int	ft_count_number(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		count;
	long	nbr;

	nbr = n;
	count = ft_count_number(nbr);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		exit(1);
	if (n < 0)
		nbr *= -1;
	res[count] = '\0';
	count--;
	while (count >= 0)
	{
		res[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
