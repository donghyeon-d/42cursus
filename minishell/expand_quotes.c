/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:23:38 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

int	count_quotes(t_token_node *node)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (node->token[++i])
	{
		if (node->token[i] == '\'')
		{
			count += 2;
			while (node->token[++i] != '\'')
				if (node->token[i] == '\0')
					break ;
		}
		if (node->token[i] == '\"')
		{
			count += 2;
			while (node->token[++i] != '\"')
				if (node->token[i] == '\0')
					break ;
		}
	}
	return (count);
}

void	filling_quoteless(t_token_node *node, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (node->token[i])
	{
		if (node->token[i] != '\'' && node->token[i] != '\"')
			new[j++] = node->token[i];
		if (node->token[i] == '\'')
			while (node->token[++i] != '\'')
				new[j++] = node->token[i];
		if (node->token[i] == '\"')
			while (node->token[++i] != '\"')
				new[j++] = node->token[i];
		i++;
	}
	new[j] = '\0';
}

void	expand_quotes(t_token_node *node)
{
	int		len;
	int		count;
	char	*new;

	count = count_quotes(node);
	if (count == 0)
		return ;
	len = ft_strlen(node->token);
	new = (char *)malloc(sizeof(char) * (len - count + 1));
	if (new == NULL)
		exit(-1);
	filling_quoteless(node, new);
	free(node->token);
	node->token = new;
}
