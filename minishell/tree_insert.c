/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:53:54 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:51:04 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"

void	insert_left_child(t_tree_node *parent_node, t_tree_node *child_node)
{
	parent_node->left = child_node;
}

void	insert_right_child(t_tree_node *parent_node, t_tree_node *child_node)
{
	parent_node->right = child_node;
}

void	insert_left_node(t_tree_node *tree_node, t_token *token)
{
	t_token_node	*temp;

	temp = token_pop_front(token);
	token_add_back(tree_node->left->token, temp);
}

void	insert_right_node(t_tree_node *tree_node, t_token *token)
{
	t_token_node	*temp;

	temp = token_pop_front(token);
	token_add_back(tree_node->right->token, temp);
}
