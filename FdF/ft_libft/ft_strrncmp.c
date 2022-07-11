/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:30:09 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/11 10:10:24 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int		i;
	int		len_s1;
	int		len_s2;

	if (n == 0)
		return (0);
	i = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (n > len_s1 || n > len_s2)
		return (-1);
	s1 += len_s1 - 1;
	s2 += len_s2 - 1;
	while (++i < n && *s1 == *s2)
	{
		s1--;
		s2--;
	}
	if (i == n)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
