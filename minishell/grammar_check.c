/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:56:21 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 15:58:35 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"
#include <stdlib.h>

int	check_rdr(t_token_node *node)
{
	t_type	next;

	if (node->type != rdr)
		return (0);
	if (node->next == NULL)
		return (1);
	next = node->next->type;
	if (next != words && next != dquote && next != squote)
		return (1);
	else
		return (0);
}

int	check_pipe(t_token_node *node)
{
	t_type	next;
	t_type	prev;

	if (node->type != pipeline && node->type != and && node->type != or)
		return (0);
	if (node->next == NULL || node->prev == NULL)
		return (1);
	next = node->next->type;
	prev = node->prev->type;
	if (next != words && next != parenth && next != squote && next != dquote
		&& next != rdr)
		return (1);
	if (prev != words && prev != parenth && prev != squote && prev != dquote)
		return (1);
	return (0);
}

int	check_parenthesis(t_token_node *node)

{
	t_type	next;
	t_type	prev;

	if (node->type != parenth)
		return (0);
	if (node->next != NULL)
	{
		next = node->next->type;
		if (next != rdr && next != pipeline && next != and && next != or)
			return (1);
	}
	if (node->prev != NULL)
	{
		prev = node->prev->type;
		if (prev != rdr && prev != pipeline && prev != and && prev != or)
			return (1);
	}
	return (0);
}

int	check_quotes(t_token_node *node)
{
	int	i;

	i = 0;
	while (node->token[i])
	{
		if (node->token[i] == '\'')
			while (node->token[++i] != '\'')
				if (node->token[i] == '\0')
					return (1);
		if (node->token[i] == '\"')
			while (node->token[++i] != '\"')
				if (node->token[i] == '\0')
					return (1);
		i++;
	}
	return (0);
}
