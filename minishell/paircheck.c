/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paircheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:47:57 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int	parentheses_pair_check(char *input)
{
	int	i;
	int	cnt;

	if (input == NULL)
		return (-1);
	i = 0;
	cnt = 1;
	while (input[++i] != '\0')
	{
		if (input[i] == '(')
			cnt++;
		else if (input[i] == ')')
		{
			cnt--;
			if (cnt == 0)
			{
				i++;
				break ;
			}
		}
		else if (input[i] == '\"' || input[i] == '\'')
			i += quote_pair_long(&input[i]) - 1;
	}
	return (i);
}

int	parentheses_pair_long(char *input)
{
	int	input_len;
	int	i;

	if (input == NULL)
		return (-1);
	input_len = ft_strlen(input);
	i = 0;
	while (++i < input_len)
	{
		if (input[i] == ')')
		{
			i++;
			break ;
		}
		else if (input[i] == '\"' || input[i] == '\'')
			i += quote_pair_long(&input[i]);
	}
	return (i);
}

int	quote_pair_long(char *input)
{
	int	i;

	if (input == NULL || (input[0] != '\'' && input[0] != '\"'))
		return (-1);
	i = 0;
	if (input[i] == '\"')
	{
		while (input[++i] != '\"' && input[i] != '\0')
			;
	}
	else if (input[i] == '\'')
	{
		while (input[++i] != '\'' && input[i] != '\0')
			;
	}
	if (input[i] == '\0')
		return (i);
	i++;
	if (input[i] == '\'' || input[i] == '\"')
		i += quote_pair_long(&(input[i]));
	return (i);
}
