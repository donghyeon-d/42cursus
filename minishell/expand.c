/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:40:29 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "type.h"

void	expanding(t_token *token, t_env *env)
{
	t_token_node	*node;

	node = token->head;
	while (node != NULL)
	{
		find_env(node, env);
		expand_tilde(node, env);
		node = node->next;
	}
	expand_wildcard(token);
	node = token->head;
	token->cnt = 0;
	while (node != NULL)
	{
		expand_quotes(node);
		node = node->next;
		token->cnt++;
	}
}
