/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 11:37:56 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*result;

	slen = ft_strlen((char *)s);
	if (slen < len || slen < (size_t)start)
		result = (char *)malloc(sizeof(char) * (slen + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	if (slen < (size_t)start)
		result[0] = 0;
	else
	{
		i = 0;
		while (s[start + i] != 0 && i < len)
		{
			result[i] = ((char *)s)[start + i];
			i++;
		}
		result[i] = 0;
	}
	return (result);
}
