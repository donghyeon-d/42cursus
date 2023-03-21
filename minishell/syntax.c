/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:22:53 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char	*take_off_parenthesis(char *str)
{
	int		i;
	int		len;
	char	*line;

	len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * (len - 1));
	if (line == NULL)
		exit(1);
	i = 0;
	while (str[i + 2])
	{
		line[i] = str[i + 1];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	skip_the_quotes(t_token_node *node, int i)
{
	while (node->token[i])
	{
		if (node->token[i] == '\"')
			while (node->token[++i] != '\"')
				if (node->token[i] == '\0')
					break ;
		if (node->token[i] == '\'')
			while (node->token[++i] != '\'')
				if (node->token[i] == '\0')
					break ;
		if (node->token[i] == '(' || node->token[i] == ')')
			return (1);
		i++;
	}
	return (0);
}

int	check_parenthesis_pair(t_token_node *node)
{
	int	i;

	i = 0;
	if (node->token[i] == '(')
	{
		while (node->token[++i] != '\0')
			if (node->token[i] == ')' && node->token[i + 1] == '\0')
				return (0);
		return (1);
	}
	else
	{
		if (skip_the_quotes(node, i))
			return (1);
	}
	return (0);
}

int	syntax_check_recur(t_token_node *node)
{
	char	*input;
	char	**word;
	t_token	*token;
	int		ret;

	input = take_off_parenthesis(node->token);
	word = split_input_to_word(input);
	token = word_to_token(word);
	ret = 0;
	if (syntax_check(token) == 1)
		ret = 1;
	free(input);
	del_word(&word);
	del_token(&token);
	return (ret);
}

int	syntax_check(t_token *token)
{
	t_token_node	*node;

	if (token == NULL || token->cnt == 0)
		return (-1);
	node = token->head;
	while (node)
	{
		if (check_rdr(node) || check_pipe(node) || check_parenthesis(node)
			|| check_quotes(node) || check_parenthesis_pair(node))
			return (1);
		if (node->token[0] == '(')
			syntax_check_recur(node);
		node = node->next;
	}
	return (0);
}
