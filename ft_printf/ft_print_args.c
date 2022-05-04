/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:19:01 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/02 19:48:48 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, t_print *print)
{
	char	str[1];

	print->len = 1;
	str[0] = c;
	ft_make_fill(print, c, 'c');
	if (print->minus)
	{
		ft_print(str, print->len, print);
		ft_print_buffer(' ', print->digit - print->len, print);
	}
	else
	{
		ft_print_buffer(print->fill, print->digit - print->len, print);
		ft_print(str, print->len, print);
	}
}

void	ft_print_str(char *str, t_print *print)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	print->len = len;
	if (print->dot)
	{
		if (print->prec <= len)
			print->len = print->prec;
		else
			print->len = len;
	}
	if (print->minus)
	{
		ft_print(str, print->len, print);
		ft_print_buffer(' ', print->digit - print->len, print);
	}
	else
	{
		ft_print_buffer(' ', print->digit - print->len, print);
		ft_print(str, print->len, print);
	}
}

void	ft_print_number(int num, t_print *print)
{
	char	*str;

	str = ft_itoa(num, print);
	if (str == NULL)
		return ;
	print->len = ft_strlen(str);
	ft_make_fill(print, num, 'd');
	if (print->minus)
	{
		ft_print_num(&print->first_sign, 1, print);
		ft_print_buffer(print->fill, print->buffer, print);
		if (!(print->dot == 1 && print->prec == 0 && num == 0))
			ft_print_num(str, print->len, print);
		ft_print_buffer(' ', print->padding, print);
	}
	else
	{
		ft_print_buffer(' ', print->padding, print);
		ft_print_num(&print->first_sign, 1, print);
		ft_print_buffer(print->fill, print->buffer, print);
		if (!(print->dot == 1 && print->prec == 0 && num == 0))
			ft_print_num(str, print->len, print);
	}
	free(str);
}

void	ft_print_basenum(size_t num, t_print *print, char type)
{
	char	*str;

	num = ft_type(type, print, num);
	print->len = ft_basenum_len(num, ft_strlen(print->base), print);
	ft_make_fill(print, num, type);
	str = ft_to_base(num, print);
	if (str == NULL)
		return ;
	if (print->minus)
	{
		ft_print(print->prefix, ft_strlen(print->prefix), print);
		ft_print_buffer('0', print->buffer, print);
		if (!(print->dot == 1 && print->prec == 0 && num == 0))
			ft_print(str, print->len, print);
		ft_print_buffer(' ', print->padding, print);
	}
	else
	{
		ft_print_buffer(' ', print->padding, print);
		ft_print(print->prefix, ft_strlen(print->prefix), print);
		ft_print_buffer('0', print->buffer, print);
		if (!(print->dot == 1 && print->prec == 0 && num == 0))
			ft_print(str, print->len, print);
	}
	free(str);
}

void	ft_printargs(t_print *print, const char *fmt, va_list *ap)
{
	if (*fmt == 'c')
		ft_print_char(va_arg(*ap, int), print);
	else if (*fmt == 's')
		ft_print_str(va_arg(*ap, char *), print);
	else if (*fmt == 'p')
		ft_print_basenum((size_t)(va_arg(*ap, void *)), print, *fmt);
	else if (*fmt == 'x' || *fmt == 'X' || *fmt == 'o' || *fmt == 'O')
		ft_print_basenum(va_arg(*ap, int), print, *fmt);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_print_number(va_arg(*ap, int), print);
	else if (*fmt == 'u')
		ft_print_basenum(va_arg(*ap, unsigned int), print, *fmt);
	else if (*fmt == '%')
		ft_print_char('%', print);
	fmt++;
}
