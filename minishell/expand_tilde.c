/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:36:21 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	change_tilde(t_token_node *node, t_env *env)
{
	char	*temp;
	char	*new;

	temp = ft_getenv(env, "HOME");
	if (temp == NULL)
	{
		write(2, "minishell: HOME not set\n", 24);
		return ;
	}
	if (node->token[1] == '/')
		new = ft_strjoin(temp, &(node->token[1]));
	else
		new = ft_strdup(temp);
	free(node->token);
	free(temp);
	node->token = new;
}

void	expand_tilde(t_token_node *node, t_env *env)
{
	if (node->token[0] == '~'
		&& (node->token[1] == '/' || node->token[1] == '\0'))
		change_tilde(node, env);
}
