/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:40:29 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 21:11:29 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"
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
