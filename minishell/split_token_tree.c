/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:18:51 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:50:39 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

void	add_and_split(t_tree_node *node, t_token_node *node_token)
{
	token_add_back(node->token, node_token);
	split_left_node(node->left);
	split_token_tree(node->right);
}

void	split_token_tree(t_tree_node *node)
{
	t_token_node	*temp;
	t_token_node	*node_token;

	if (node == NULL || node->token == NULL || node->token->cnt == 0)
		return ;
	node_token = NULL;
	temp = token_pop_front(node->token);
	while (temp != NULL && !is_type_delimiter(temp))
	{
		token_to_child(node, temp, LEFT);
		temp = token_pop_front(node->token);
	}
	if (is_type_delimiter(temp))
	{
		node->type = temp->type;
		node_token = temp;
		temp = token_pop_front(node->token);
	}
	while (temp != NULL)
	{
		token_to_child(node, temp, RIGHT);
		temp = token_pop_front(node->token);
	}
	add_and_split(node, node_token);
}
