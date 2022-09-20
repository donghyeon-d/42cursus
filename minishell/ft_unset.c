/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:47:44 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 15:55:47 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

void	del_env_one(t_env *del)
{
	if (del == NULL)
		return ;
	free(del->key);
	free(del->value);
	free(del);
}

void	env_pop(t_env **node, char *key)
{
	t_env	*del;
	t_env	*tmp;

	del = *node;
	tmp = del;
	if (ft_strsame(del->key, key))
	{
		tmp = tmp->next;
		del_env_one(del);
		node = &tmp;
		tmp = NULL;
	}
	while (tmp)
	{
		del = tmp->next;
		if (del == NULL)
			return ;
		if (ft_strsame(del->key, key))
		{
			tmp->next = tmp->next->next;
			del_env_one(del);
			return ;
		}
		tmp = tmp->next;
	}
}

int	ft_unset(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->argv[i])
	{
		env_pop(&(cmd->env), cmd->argv[i]);
		i++;
	}
	return (0);
}
