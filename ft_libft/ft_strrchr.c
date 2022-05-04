/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:49 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 11:32:31 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*locate;

	locate = (char *)s + ft_strlen((char *)s);
	while (*locate != (unsigned char)c && locate != s)
		locate--;
	if (*locate == (unsigned char)c)
		return (locate);
	else
		return (0);
}
