/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:24:10 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/24 10:19:34 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_issep(char const s, char c)
{
	if ((char)s == c)
		return (1);
	return (0);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (c == 0 && *s != 0)
		return (1);
	while (s[i] != 0)
	{
		while (ft_issep(s[i], c) && s[i] != 0)
			i++;
		if (!(ft_issep(s[i], c)) && s[i] != 0)
			count++;
		while (!(ft_issep(s[i], c)) && s[i] != 0)
			i++;
	}
	return (count);
}

static char	*ft_word(char const *s, char c)
{
	size_t	wordlen;
	size_t	i;
	char	*word;

	i = 0;
	wordlen = 0;
	while (ft_issep(s[i], c) && s[i] != 0)
		i++;
	while (!ft_issep(s[i], c) && s[i] != 0)
	{
		i++;
		wordlen++;
	}
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_wordfree(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	wordcount;
	size_t	i;

	wordcount = ft_wordcount(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (ft_issep(*s, c) && *s)
			s++;
		if (*s)
		{
			result[i] = ft_word(s, c);
			if (result[i] == NULL)
				return (ft_wordfree(result, i));
			i++;
		}
		while (!(ft_issep(*s, c)) && *s)
			s++;
	}
	result[i] = NULL;
	return (result);
}
