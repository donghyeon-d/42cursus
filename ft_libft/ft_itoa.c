/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:10:21 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 10:58:12 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len += 2;
		n /= -10;
	}
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
	int		i;

	len = ft_ilen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == 0)
		return (0);
	i = 0;
	num[len] = 0;
	if (n == 0)
		num[0] = '0';
	if (n < 0)
	{
		num[0] = '-';
		num[len-- - 1] = -(n % 10) + '0';
		n /= -10;
	}
	while (n > 0)
	{
		num[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
