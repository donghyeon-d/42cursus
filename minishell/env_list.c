/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:22:59 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 18:19:02 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

t_env	*new_env(char *str, int len)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		exit(1);
	if (len == 0)
	{
		new->key = ft_strdup(str);
		new->value = NULL;
	}
	else
	{
		new->key = ft_strndup(str, len);
		new->value = ft_strdup(&(str[len + 1]));
	}
	if (new->key == NULL)
		exit(1);
	new->next = NULL;
	return (new);
}

void	env_add_back(t_env *node, t_env *tmp)
{
	if (node == NULL)
		return ;
	while (node->next)
		node = node->next;
	node->next = tmp;
}

void	del_env(t_env **node)
{
	t_env	*del;
	t_env	*tmp;

	if (*node == NULL)
		return ;
	del = *node;
	tmp = del;
	while (tmp)
	{
		tmp = tmp->next;
		free(del->key);
		free(del->value);
		free(del);
		del = tmp;
	}
	*node = NULL;
}

char	**envlist_to_str(t_env *env)
{
	int		i;
	t_env	*tmp;
	char	**ret;

	tmp = env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (ret == NULL)
		exit(1);
	i = 0;
	while (env)
	{
		if (env->value != NULL)
			ret[i++] = ft_strjoin_with_c(env->key, env->value, '=');
		env = env->next;
	}
	ret[i] = NULL;
	return (ret);
}

t_env	*create_env_list(char **env)
{
	int		len;
	int		i;
	int		j;
	t_env	*tmp;
	t_env	*node;

	i = 0;
	while (env[i])
	{
		j = 0;
		len = 0;
		while (env[i][j++] != '=' && env[i][j] != '\0')
			len++;
		if (i == 0)
			node = new_env(env[i], len);
		else
		{
			tmp = new_env(env[i], len);
			env_add_back(node, tmp);
		}
		i++;
	}
	return (node);
}
