/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freeflag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:40:28 by choidongd         #+#    #+#             */
/*   Updated: 2022/09/20 17:49:59 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_freeflag(char const *s1, char const *s2, int f1, int f2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	result[s1_len + s2_len] = '\0';
	i = -1;
	while (((char *)s1)[++i])
		result[i] = ((char *)s1)[i];
	i = -1;
	while (((char *)s2)[++i])
		result[i + s1_len] = ((char *)s2)[i];
    if (f1 != 0)
        free(s1);
    if (f2 != 0)
        free(s2);
	return (result);
}
