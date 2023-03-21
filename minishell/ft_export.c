/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:43:34 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	export_print(t_cmd *cmd)
{
	while (cmd->env)
	{
		write(cmd->fd_out, "declare -x ", 11);
		write(cmd->fd_out, cmd->env->key, ft_strlen(cmd->env->key));
		if (cmd->env->value != NULL)
		{
			write(cmd->fd_out, "=", 1);
			write(cmd->fd_out, "\"", 1);
			write(cmd->fd_out, cmd->env->value, ft_strlen(cmd->env->value));
			write(cmd->fd_out, "\"", 1);
		}
		write(cmd->fd_out, "\n", 1);
		cmd->env = cmd->env->next;
	}
}

int	key_check(char *line, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		if (i == 0)
			if (line[i] != '_' && !ft_isalpha(line[i]))
				return (1);
		if (line[i] != '_' && !ft_isdigit(line[i]) && \
			!ft_isalpha(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	key_and_value(t_cmd *cmd, char *line, int i)
{
	t_env	*tmp;

	if (key_check(line, i))
		return (1);
	while (ft_strncmp(line, cmd->env->key, i))
	{
		if (cmd->env->next == NULL)
		{
			tmp = new_env(line, i);
			env_add_back(cmd->env, tmp);
			return (0);
		}
		cmd->env = cmd->env->next;
	}
	free(cmd->env->value);
	cmd->env->value = ft_strdup(&(line[i + 1]));
	return (0);
}

int	export_add_env(t_cmd *cmd, char *line)
{
	int		i;
	int		status;
	t_env	*tmp;

	status = 0;
	i = 0;
	while (line[i] != '=' && line[i] != '\0')
		i++;
	if (line[i] == '=')
		return (key_and_value(cmd, line, i));
	if (key_check(line, i))
		return (1);
	while (!ft_strsame(line, cmd->env->key))
	{
		if (cmd->env->next == NULL)
		{
			tmp = new_env(line, 0);
			env_add_back(cmd->env, tmp);
			return (0);
		}
		cmd->env = cmd->env->next;
	}
	return (status);
}

int	ft_export(t_cmd *cmd)
{
	int	status;
	int	i;

	if (cmd->argc == 1)
	{
		export_print(cmd);
		return (0);
	}
	status = 1;
	i = 1;
	while (cmd->argv[i])
	{
		status = export_add_env(cmd, cmd->argv[i]);
		i++;
	}
	if (status == 1)
		custom_error(cmd, "not a valid identifier", 0);
	return (status);
}
