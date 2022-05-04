/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:09:18 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 11:25:42 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*result;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == 0)
		return (0);
	result[s1_len + s2_len] = 0;
	i = 0;
	while (((char *)s1)[i])
	{
		result[i] = ((char *)s1)[i];
		i++;
	}
	i = 0;
	while (((char *)s2)[i])
	{
		result[i + s1_len] = ((char *)s2)[i];
		i++;
	}
	return (result);
}
