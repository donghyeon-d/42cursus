/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:00:20 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*result;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (slen < len || slen < (size_t)start)
		result = (char *)malloc(sizeof(char) * (slen + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (slen >= (size_t)start)
	{
		while (s[start + i] != '\0' && i < len)
		{
			result[i] = ((char *)s)[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
