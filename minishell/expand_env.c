/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:51:10 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 15:28:28 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

char	*ft_getenv(t_env *env, char *key)
{
	char	*value;

	while (env)
	{
		if (ft_strsame(env->key, key))
		{
			value = ft_strdup(env->value);
			if (value == NULL)
				exit(1);
			else
				return (value);
		}
		env = env->next;
	}
	return (NULL);
}

void	find_env(t_token_node *node, t_env *env)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (node->token[i])
	{
		if (node->token[i] == '\"')
		{
			if (flag == 0)
				flag++;
			else
				flag--;
		}
		if (node->token[i] == '\'' && flag == 0)
			while (node->token[++i] != '\'')
				if (node->token[i] == '\0')
					break ;
		if (node->token[i] == '$' && node->token[i + 1] != '$'
			&& node->token[i + 1] != ' ' && node->token[i + 1] != '\"'
			&& node->token [i + 1] != '/' && node->token[i + 1] != '\0')
			i = match_env(node, env, i);
		i++;
	}
}
