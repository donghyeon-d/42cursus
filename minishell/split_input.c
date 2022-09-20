/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:42:54 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 23:34:53 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

static int	is_input_separate(char *c)
{
	if (c[0] == '<' || c[0] == '>' || c[0] == '|')
		return (TRUE);
	if (c[0] == '&' && c[1] == '&')
		return (TRUE);
	return (FALSE);
}

int	get_word_cnt(char *input)
{
	int	cnt;
	int	i;

	if (input == NULL || input[0] == '\0')
		return (0);
	i = -1;
	cnt = 0;
	while (input[++i])
	{
		while (input[i] == ' ')
			i++;
		if (input[i] == '\0')
			break ;
		i += get_word_len(&(input[i])) - 1;
		cnt++;
	}
	return (cnt);
}

void	input_to_word(char *input, char **word, int word_cnt)
{
	int	i;
	int	len;
	int	word_idx;

	i = -1;
	word_idx = -1;
	while (input[++i])
	{
		len = 0;
		while (input[i] == ' ')
			i++;
		len = get_word_len(&(input[i]));
		word[++word_idx] = ft_strndup(&input[i], len);
		if (word[word_idx] == NULL && len > 0)
			exit(1);
		i += len - 1;
	}
	word[word_cnt] = NULL;
}

int	get_word_len(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i + len] != '\0' && input[i + len] != ' ')
	{
		if (is_input_separate(&input[i + len]))
		{
			if (len != 0)
				break ;
			if (input[i + len] == input[i + len + 1])
				return (2);
			return (1);
		}
		if (input[i + len] == '(')
			len += parentheses_pair_check(&input[i + len]);
		else if (input[i + len] == '\'' || input[i + len] == '\"')
			len += quote_pair_long(&(input[i + len]));
		else
		{
			len++;
		}
	}
	return (len);
}

char	**split_input_to_word(char *input)
{
	char	**word;
	int		word_cnt;

	if (input == NULL)
		return (NULL);
	word_cnt = get_word_cnt(input);
	word = malloc(sizeof(char *) * (word_cnt + 1));
	if (word == NULL)
		exit(1);
	input_to_word(input, word, word_cnt);
	return (word);
}
