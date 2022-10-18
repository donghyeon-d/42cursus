/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:54 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/13 17:30:50 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

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
		if (result > LONG_MAX + (unsigned long)1 && sign < 0)
			return (0);
		if (result > LONG_MAX && sign > 0)
			return (-1);
		i++;
	}
	return ((int)(sign * result));
}
