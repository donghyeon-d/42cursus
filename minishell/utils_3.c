/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:25:09 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:47:29 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		exit (1);
	i = 0;
	while (i < len)
	{
		result[i] = ((char *)s1)[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	*ft_calloc(int count, int size)
{
	void	*temp;

	temp = malloc(size * count);
	if (temp == 0)
		exit (1);
	return (ft_memset(temp, 0, count * size));
}

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*ft_strjoin_with_space(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (result == NULL)
		exit (1);
	result[s1_len + s2_len + 1] = '\0';
	i = -1;
	while (s1 != NULL && s1[++i])
		result[i] = s1[i];
	if (s1 != NULL)
		result[i] = ' ';
	else
		result[s1_len + s2_len] = '\0';
	i = -1;
	while (s1 == NULL && s2[++i])
		result[i + s1_len] = s2[i];
	while (s1 != NULL && s2[++i])
		result[i + s1_len + 1] = s2[i];
	free(s1);
	return (result);
}

char	*ft_strjoin_with_c(char *s1, char *s2, char c)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (result == NULL)
		exit (1);
	result[s1_len + s2_len + 1] = '\0';
	i = -1;
	while (s1 != NULL && s1[++i])
		result[i] = s1[i];
	if (s1 != NULL)
		result[i] = c;
	else
		result[s1_len + s2_len] = '\0';
	i = -1;
	while (s1 == NULL && s2[++i])
		result[i + s1_len] = s2[i];
	while (s1 != NULL && s2[++i])
		result[i + s1_len + 1] = s2[i];
	return (result);
}
