/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:25:34 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/04 15:25:36 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	ft_strlen(char *str)
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

	if (argv == NULL)
		return (LLONG_MAX);
	num = 0;
	len = ft_strlen(argv);
	sign = 1;
	i = 0;
	if (argv[i] == '-')
		sign *= -1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (i < len && ft_isdigit(argv[i]))
		num = num * 10 + argv[i++] - '0';
	num *= sign;
	if (i < len)
		num = LLONG_MAX;
	if ((argv[0] == '-' || argv[0] == '+') && !ft_isdigit(argv[1]))
		num = LLONG_MAX;
	return (num);
}
