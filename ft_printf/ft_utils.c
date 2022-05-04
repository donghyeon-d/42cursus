/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:39:40 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/02 19:41:20 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	if (str == NULL || *str == '\0')
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_num_len(ssize_t num, t_print *print)
{
	size_t	num_len;

	num_len = 0;
	if (num == 0)
		num_len = 1;
	if (num < 0)
	{
		num /= -10;
		num_len += 1;
		print->first_sign = '-';
	}
	while (num > 0)
	{
		num /= 10;
		num_len++;
	}
	return (num_len);
}

size_t	ft_basenum_len(size_t num, int base_len, t_print *print)
{
	size_t	num_len;

	num_len = 0;
	if (num == 0)
		num_len = 1;
	if (num < 0)
	{
		num /= -base_len;
		num_len += 2;
		print->first_sign = '-';
	}
	while (num > 0)
	{
		num /= base_len;
		num_len++;
	}
	return (num_len);
}

char	*ft_to_base(size_t num, t_print *print)
{
	char	*result;
	int		baselen;
	int		numlen;

	baselen = ft_strlen(print->base);
	numlen = print->len;
	result = (char *)malloc(sizeof(char) * (numlen + 1));
	if (result == NULL)
	{
		print->error = 1;
		return (NULL);
	}
	result[numlen] = '\0';
	while (--numlen >= 0)
	{
		result[numlen] = print->base[num % baselen];
		num = num / baselen;
	}
	return (result);
}

char	*ft_itoa(int num, t_print *print)
{
	char	*str;
	int		strlen;

	strlen = ft_num_len(num, print);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
	{
		print->error = 1;
		return (NULL);
	}		
	str[strlen] = '\0';
	if (num < 0)
	{
		str[--strlen] = -(num % 10) + '0';
		num /= -10;
	}
	while (--strlen >= 0)
	{
		str[strlen] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
