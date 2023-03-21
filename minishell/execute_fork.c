/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:23:09 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "minishell.h"

static void	execute_set_childfd(t_cmd *cmd, int prev_in)
{
	if (cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(prev_in);
	}
	else if (prev_in > -1)
		dup2(prev_in, 0);
	close(cmd->pipe[0]);
	if (cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->pipe[1]);
	}
	else if (cmd->pipe[1] > -1)
		dup2(cmd->pipe[1], 1);
}

static void	execute_fork_else(t_cmd *cmd)
{
	char	**envp;

	envp = envlist_to_str(cmd->env);
	if (execve(cmd->cmd, cmd->argv, envp))
	{
		print_error_exit(nocmd);
		del_word(&envp);
		exit(127);
	}
}

int	execute_fork(t_cmd *cmd, int prev_in)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		set_signal(SIG_DFL, SIG_DFL);
		execute_set_childfd(cmd, prev_in);
		if (cmd->is_builtin == TRUE)
			exit(execute_built_in_func(cmd));
		else if (cmd->argv != NULL && cmd->argv[0] != NULL && \
		cmd->argv[0][0] == '(')
			g_status = execute_parenthesis(cmd);
		else
			execute_fork_else(cmd);
	}
	else
	{
		set_signal(SIG_IGN, SIG_IGN);
		close(prev_in);
		close((cmd->pipe)[1]);
		cmd->pid = pid;
	}
	return (0);
}
