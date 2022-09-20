/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:51:15 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/12 16:34:46 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

void	del(t_tree **tree, t_token **token, char **input, t_cmd **cmd)
{
	if (*tree != NULL)
		del_tree(tree);
	if (*token != NULL)
		del_token(token);
	if (input != NULL && *input != NULL)
	{
		free(*input);
		*input = NULL;
	}
	if (*cmd != NULL)
		del_cmd(cmd);
}

void	del_tree(t_tree **tree)
{
	traversal_fucn((*tree)->root, del_tree_node);
	free (*tree);
	*tree = NULL;
}

void	del_tree_node(t_tree_node **tree_node)
{
	del_token(&((*tree_node)->token));
	free(*tree_node);
	tree_node = NULL;
}

void	del_token_node(t_token_node **token_node)
{
	free((*token_node)->token);
	free(*token_node);
	*token_node = NULL;
}

void	del_word(char ***word)
{
	int	i;

	i = -1;
	if (*word == NULL)
		return ;
	while ((*word)[++i] != NULL)
		free((*word)[i]);
	free((*word));
	*word = NULL;
}
