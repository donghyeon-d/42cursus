/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:27:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/20 17:48:29 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*buf;

	buf = ft_itoa(n);
	ft_putstr_fd(buf, fd);
	free(buf);
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	temp;

// 	if (n == -2147483648)
// 		ft_putstr_fd("-2147483648", fd);
// 	else if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(-n, fd);
// 	}
// 	else if (n > 9)
// 	{
// 		temp = (char)(n % 10) + 48;
// 		n /= 10;
// 		ft_putnbr_fd(n, fd);
// 		ft_putchar_fd(temp, fd);
// 	}
// 	else
// 	{
// 		temp = (char)n + 48;
// 		ft_putchar_fd(temp, fd);
// 	}
// }
