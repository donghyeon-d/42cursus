/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:27:59 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 11:32:39 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_newstrlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)s1);
	if (*set == 0)
		return (len);
	while (ft_isset(s1[i], set))
		i++;
	if (len == i)
		return (0);
	while (ft_isset(s1[len - 1], set) && len > 0)
		len--;
	len -= i;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = ft_newstrlen(s1, set);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	while (ft_isset(*s1, set))
		s1++;
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
