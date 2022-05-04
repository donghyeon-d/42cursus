/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:35:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/04/29 10:56:31 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *str, int len, t_print *print)
{
	int	n;

	n = write(1, str, len);
	if (n == -1)
		print->error = 1;
	print->ret += n;
}

void	ft_print_num(char *str, int len, t_print *print)
{
	int	n;

	if (*str == '\0')
		return ;
	n = write(1, str, len);
	if (n == -1)
		print->error = 1;
	print->ret += n;
}

void	ft_print_buffer(char c, int len, t_print *print)
{
	int	n;
	int	i;

	if (len <= 0)
		return ;
	i = 0;
	n = 0;
	while (i < len)
	{
		n = write(1, &c, 1);
		if (n == -1)
			print->error = 1;
		print->ret += n;
		i++;
	}
}
