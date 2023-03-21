/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:51:35 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

t_tree	*creat_tree(void)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	if (tree == NULL)
		exit(1);
	tree->root = NULL;
	tree->node_cnt = 0;
	return (tree);
}

t_tree_node	*creat_tree_node(void)
{
	t_tree_node	*node;

	node = malloc(sizeof(t_tree_node));
	if (node == NULL)
		exit(1);
	node->token = NULL;
	node->visited = 0;
	node->type = words;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
