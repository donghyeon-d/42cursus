/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:18:43 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/24 19:32:29 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}
