/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:46:00 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	find_pattern(t_token_node *node, t_token *token)
{
	t_token_node	*temp;

	temp = make_wc_list(node);
	if (temp)
	{
		temp->prev = node->prev;
		if (node->prev != NULL)
			node->prev->next = temp;
		if (node == token->head)
			token->head = temp;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = node->next;
			if (node->next != NULL)
				node->next->prev = temp;
			del_token_node(&node);
		}
	}
}

void	expand_wildcard(t_token *token)
{
	int				i;
	t_token_node	*node;

	node = token->head;
	while (node)
	{
		i = -1;
		while (node->token[++i])
		{
			if (node->token[i] == '\'')
				while (node->token[++i] != '\'')
					if (node->token[i] == '\0')
						break ;
			if (node->token[i] == '\"')
				while (node->token[++i] != '\'')
					if (node->token[i] == '\0')
						break ;
			if (node->token[i] == '*')
			{
				find_pattern(node, token);
				break ;
			}
		}
		node = node->next;
	}
}
