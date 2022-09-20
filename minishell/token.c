/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:28:01 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 16:40:06 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

void	define_type(t_token_node *token, char *word)
{
	if (word[0] == '(')
		token->type = parenth;
	else if (word[0] == '\'')
		token->type = squote;
	else if (word[0] == '\"')
		token->type = dquote;
	else if (ft_strsame(word, "&&"))
		token->type = and;
	else if (ft_strsame(word, "||"))
		token->type = or;
	else if (ft_strsame(word, "|"))
		token->type = pipeline;
	else if (ft_strsame(word, ">"))
		token->type = rdr;
	else if (ft_strsame(word, "<"))
		token->type = rdr;
	else if (ft_strsame(word, ">>"))
		token->type = rdr;
	else if (ft_strsame(word, "<<"))
		token->type = rdr;
	else
		token->type = words;
}

t_token	*word_to_token(char **word)
{
	t_token			*token;
	t_token_node	*node;
	int				i;

	if (word == NULL)
		return (NULL);
	token = create_token();
	i = -1;
	while (word[++i] != NULL)
	{
		node = create_token_node(ft_strdup(word[i]));
		if (node->token == NULL)
			exit(1);
		define_type(node, node->token);
		token_add_back(token, node);
	}
	return (token);
}
