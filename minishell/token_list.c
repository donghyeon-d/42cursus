/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:26:01 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

t_token	*create_token(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		exit(1);
	new->cnt = 0;
	new->head = NULL;
	return (new);
}

t_token_node	*create_token_node(char *data)
{
	t_token_node	*new;

	new = malloc(sizeof(t_token_node));
	if (new == NULL)
		exit(1);
	new->token = data;
	if (new->token == NULL)
		exit(1);
	define_type(new, new->token);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	token_add_back(t_token *token, t_token_node *node)
{
	t_token_node	*temp;

	if (token == NULL || node == NULL)
		return ;
	if (token->cnt == 0)
		token->head = node;
	else if (token->cnt == 1)
	{
		token->head->next = node;
		node->prev = token->head;
	}
	else
	{
		temp = token->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
	token->cnt++;
}

t_token_node	*token_pop_front(t_token *token)
{
	t_token_node	*temp;

	if (token == NULL || token->cnt == 0)
		return (NULL);
	temp = token->head;
	token->head = temp->next;
	if (token->cnt > 1)
	{
		token->head->prev = NULL;
		if (token->cnt > 2)
			token->head->next->prev = token->head;
	}
	temp->next = NULL;
	temp->prev = NULL;
	token->cnt--;
	return (temp);
}

void	del_token(t_token **token)
{
	t_token_node	*token_node;
	t_token_node	*del_node;

	token_node = (*token)->head;
	del_node = token_node;
	while (token_node != NULL)
	{
		token_node = token_node->next;
		del_token_node(&del_node);
		del_node = token_node;
	}
	free(*token);
	*token = NULL;
}
