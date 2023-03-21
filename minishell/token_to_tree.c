/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:57:58 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

t_tree	*make_token_tree(t_token *token)
{
	t_tree			*tree;
	t_tree_node		*root;
	t_token_node	*token_node;

	if (token == NULL)
		return (NULL);
	tree = creat_tree();
	root = creat_tree_node();
	root->token = create_token();
	token_node = token_pop_front(token);
	while (token_node != NULL)
	{
		token_add_back(root->token, token_node);
		token_node = token_pop_front(token);
	}
	tree->root = root;
	return (tree);
}

void	token_to_child(t_tree_node *parent, t_token_node *node, int d)
{
	if (parent == NULL || node == NULL)
		return ;
	if (d == LEFT)
	{
		if (parent->left == NULL)
			parent->left = creat_tree_node();
		if (parent->left->token == NULL)
			parent->left->token = create_token();
		token_add_back(parent->left->token, node);
	}
	else if (d == RIGHT)
	{
		if (parent->right == NULL)
			parent->right = creat_tree_node();
		if (parent->right->token == NULL)
			parent->right->token = create_token();
		token_add_back(parent->right->token, node);
	}
}

void	split_left_node(t_tree_node *node)
{
	t_token_node	*temp;

	if (node == NULL || node->token->cnt < 3)
		return ;
	temp = token_pop_front(node->token);
	while (temp != NULL)
	{
		if (temp->type != rdr)
			token_to_child(node, temp, RIGHT);
		else
		{
			token_to_child(node, temp, LEFT);
			temp = token_pop_front(node->token);
			token_to_child(node, temp, LEFT);
		}
		temp = token_pop_front(node->token);
	}
	split_left_rdr(node->left);
}

void	split_left_rdr(t_tree_node *node)
{
	t_token_node	*temp;

	if (node == NULL || node->token == NULL)
		return ;
	temp = token_pop_front(node->token);
	token_to_child(node, temp, LEFT);
	temp = token_pop_front(node->token);
	token_to_child(node, temp, LEFT);
	temp = token_pop_front(node->token);
	while (temp != NULL)
	{
		token_to_child(node, temp, RIGHT);
		temp = token_pop_front(node->token);
	}
	split_left_rdr(node->right);
}
