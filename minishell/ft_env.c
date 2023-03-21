/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:45:24 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd)
{
	while (cmd->env)
	{
		if (cmd->env->value != NULL)
		{
			write(cmd->fd_out, cmd->env->key, ft_strlen(cmd->env->key));
			write(cmd->fd_out, "=", 1);
			write(cmd->fd_out, cmd->env->value, ft_strlen(cmd->env->value));
			write(cmd->fd_out, "\n", 1);
		}
		cmd->env = cmd->env->next;
	}
	return (0);
}
