/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:15:33 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 13:59:50 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*locate;

	if (s == NULL)
		return (NULL);
	locate = (char *)s;
	while ((char)*locate != (char)c && *locate != '\0')
		locate++;
	if (*locate == '\0' && c != '\0')
		return (NULL);
	return (locate);
}
