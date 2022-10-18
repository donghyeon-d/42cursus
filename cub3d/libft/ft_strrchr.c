/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:49 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:00:16 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*locate;

	if (s == NULL)
		return (NULL);
	locate = (char *)s + ft_strlen((char *)s);
	while (*locate != (unsigned char)c && locate != s)
		locate--;
	if (*locate == (unsigned char)c)
		return (locate);
	else
		return (NULL);
}
