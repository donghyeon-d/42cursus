/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:54 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 13:35:23 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = -1;
	sign = 1;
	result = 0;
	if ('+' == *str || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (!ft_isdigit(*str))
			exit(1);
	}	
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			break ;
		if (str[i] != '\n')
			result = result * 10 + (str[i] - '0');
	}
	if ((str[i] != '\0' && !ft_isdigit(str[i])))
		exit(1);
	return ((int)(sign * result));
}
