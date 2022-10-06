/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:30:09 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 21:02:16 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && i < n - 1)
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] < str2[i])
		return (-1);
	return (0);
}


// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	if (n == 0)
// 		return (0);
// 	i = -1;
// 	while (++i < n && s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
// 	}
// 	if (i == n)
// 		return (0);
// 	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
// }

// int main()
// {
// 	printf("%d\n", ft_strncmp("NO ./path_to_the_north_texture\n", "NO ", 4));

// }
