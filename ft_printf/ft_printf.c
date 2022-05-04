/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:03:35 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/02 19:37:57 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == '%')
		return (1);
	else if (ft_isdigit(c) || c == '#' || c == ' ' || c == '+' || c == '-' )
		return (2);
	else if (c == '.')
		return (2);
	return (0);
}

void	ft_printinit(t_print *print, int ret)
{
	print->len = 0;
	print->digit = 0;
	print->ret = ret;
	print->prefix = 0;
	print->sharp = 0;
	print->minus = 0;
	print->zero = 0;
	print->dot = 0;
	print->prec = 0;
	print->buffer = 0;
	print->padding = 0;
	print->fill = ' ';
	print->first_sign = '\0';
	print->base = "0123456789";
	print->error = 0;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print	print;

	ft_printinit(&print, 0);
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_flag(&print, (char **)&fmt);
			ft_printargs(&print, fmt, &ap);
		}
		else
			ft_print_char(*fmt, &print);
		if (print.error)
			return (-1);
		fmt++;
		ft_printinit(&print, print.ret);
	}
	va_end(ap);
	return (print.ret);
}
