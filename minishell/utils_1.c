/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:21:16 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:24:05 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (-1);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

int	ft_strsame(char *s1, char *s2)
{
	int	i;
	int	len1;
	int	len2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (0);
	i = -1;
	while (++i < len1)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

char	*ft_strndup(char *s1, int len)
{
	int		i;
	char	*result;

	if (s1 == NULL || len < 1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		exit (1);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
