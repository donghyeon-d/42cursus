/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:30:03 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int	is_type_delimiter(t_token_node *node)
{
	if (node == NULL)
		return (0);
	if (node->type == pipeline || node->type == and || node->type == or)
		return (1);
	return (0);
}

int	is_type_words(t_token_node *node)
{
	if (node == NULL)
		return (0);
	if (node->type == words || node->type == squote || node->type == dquote)
		return (1);
	return (0);
}

int	is_type_parenthesis(t_token_node *node)
{
	int	i;

	i = 0;
	if (node->token[i] == '(')
	{
		while (node->token[++i] != '\0')
			if (node->token[i] == ')' && node->token[i + 1] == '\0')
				return (0);
	}
	return (1);
}
