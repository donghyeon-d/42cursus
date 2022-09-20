/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:18:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/20 17:47:41 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*locate;
	size_t			i;

	i = 0;
	locate = (unsigned char *)s;
	while (i < n)
	{
		if (*locate == (unsigned char)c)
			return ((void *)locate);
		locate++;
		i++;
	}
	return (NULL);
}
