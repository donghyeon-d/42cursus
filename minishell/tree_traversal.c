/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_traversal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:47:08 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:31:40 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "a.h"

void	traversal_print(t_tree_node *node)
{
	t_token_node	*token_node;

	if (node == NULL)
		return ;
	token_node = node->token->head;
	while (token_node != NULL)
	{
		printf("[%d] %s ", token_node->type, token_node->token);
		token_node = token_node->next;
	}
	printf("\n");
	traversal_print(node->left);
	traversal_print(node->right);
}

void	traversal_fucn(t_tree_node *root, void (*fp)(t_tree_node **))
{
	if (root == NULL || fp == NULL)
		return ;
	if (root->left != NULL)
		traversal_fucn(root->left, fp);
	if (root->right != NULL)
		traversal_fucn(root->right, fp);
	fp(&root);
}

void	traversal_cmd_set(t_tree_node *root, t_cmd *cmd)
{
	if (root == NULL || cmd == NULL)
		return ;
	cmd_set(cmd, root->token);
	if (root->left != NULL)
		traversal_cmd_set(root->left, cmd);
	if (root->right != NULL)
		traversal_cmd_set(root->right, cmd);
}

void	traversal_heredoc_set(t_tree_node *root, t_cmd *cmd)
{
	if (root == NULL || cmd == NULL)
		return ;
	heredoc_set(cmd, root->token);
	if (root->left != NULL)
		traversal_heredoc_set(root->left, cmd);
	if (root->right != NULL)
		traversal_heredoc_set(root->right, cmd);
}
