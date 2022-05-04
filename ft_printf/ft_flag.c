/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:03:47 by dongchoi          #+#    #+#             */
/*   Updated: 2022/04/29 13:00:48 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec(t_print *print, char **fmt)
{
	int	len;
	int	in;

	len = 0;
	in = 0;
	(*fmt)++;
	print->dot = 1;
	while (ft_isdigit(**fmt))
	{
		len = (len * 10) + **fmt - '0';
		(*fmt)++;
		in = 1;
	}
	if (len == 0 || in == 1)
		(*fmt)--;
	print->prec = len;
}

void	ft_width(t_print *print, char **fmt)
{
	int	len;

	len = 0;
	while (ft_isdigit(**fmt))
	{
		len = (len * 10) + **fmt - '0';
		(*fmt)++;
	}
	(*fmt)--;
	print->digit = len;
}

void	ft_flag(t_print *print, char **fmt)
{
	while (ft_check_type(**fmt) == 2)
	{
		if (**fmt == '-')
			print->minus = 1;
		else if (**fmt == '+')
			print->first_sign = '+';
		else if (**fmt == ' ')
			print->first_sign = ' ';
		else if (**fmt == '#')
			print->sharp = 1;
		else if (**fmt == '0')
			print->zero = 1;
		else if (**fmt == '.')
			ft_prec(print, fmt);
		else if (ft_isdigit(**fmt) && **fmt != '0')
			ft_width(print, fmt);
		(*fmt)++;
	}
}

void	ft_make_fill(t_print *print, int num, char type)
{
	if (print->zero)
		print->fill = '0';
	if (print->prec > 0 && type != 'c')
		print->fill = '0';
	print->buffer = print->prec;
	if (print->len > 0)
		print->buffer -= print->len;
	print->padding = print->digit;
	if (print->buffer > 0)
		print->padding -= print->buffer;
	if (print->len > 0)
		print->padding -= print->len;
	if (print->first_sign)
		print->padding--;
	if (print->prefix)
		print->padding -= ft_strlen(print->prefix);
	if (print->dot == 1 && print->prec == 0 && num == 0)
		print->padding++;
	if (print->zero && !print->dot && type != 'p')
	{
		print->buffer = print->padding;
		print->padding = 0;
	}
}

size_t	ft_type(char type, t_print *print, size_t num)
{
	size_t	n;

	n = num;
	if (type != 'p' && n > 4294967296)
		n %= 4294967296;
	if (print->sharp && n != 0)
	{
		if (type == 'x')
			print->prefix = "0x";
		else if (type == 'X')
			print->prefix = "0X";
		else if (type == 'o' || type == 'O')
			print->prefix = "0";
	}
	if (type == 'p')
		print->prefix = "0x";
	if (type == 'x' || type == 'p')
		print->base = "0123456789abcdef";
	else if (type == 'X')
		print->base = "0123456789ABCDEF";
	else if (type == 'o' || type == 'O')
		print->base = "01234567";
	return (n);
}
