/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parenthesis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:16:07 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:41:07 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "a.h"

static t_cmd	*cmd_dup(t_info *info, t_cmd *cmd)
{
	t_cmd	*new;

	new = create_cmd(info->env);
	new->fd_in = cmd->fd_in;
	new->fd_out = cmd->fd_out;
	new->env = info->env;
	new->pipe[0] = cmd->pipe[0];
	new->pipe[1] = cmd->pipe[1];
	return (new);
}

static void	setting(t_info *info, t_cmd *cmd)
{
	pid_t	pid;

	expanding(info->token, info->env);
	info->tree = make_token_tree(info->token);
	split_token_tree(info->tree->root);
	info->cmd = cmd_dup(info, cmd);
	pid = fork();
	if (pid == 0)
	{
		set_signal(SIG_DFL, SIG_IGN);
		traversal_heredoc_set(info->tree->root, info->cmd);
		exit(g_status);
	}
	else if (pid > 0)
	{
		set_signal(SIG_IGN, SIG_IGN);
		wait_heredoc();
	}
	else
		exit(1);
	traversal_cmd_set(info->tree->root, info->cmd);
}

static void	set_and_execute(t_info *info, char *input, t_cmd *cmd)
{
	int	status;

	info->token = parsing(input);
	status = syntax_check(info->token);
	if (status == 0)
	{
		setting(info, cmd);
		if (g_status != -1)
			g_status = execute(info->cmd);
		else
			g_status = 1;
	}
	else
	{
		g_status = 258;
		write(2, "minishell: syntax error\n", 24);
	}
	unlink_tempfiles(info->cmd);
	del(&(info->tree), &(info->token), NULL, &(info->cmd));
	info->cmd = NULL;
}

int	execute_parenthesis(t_cmd *cmd)
{
	char	*input;
	char	**envp;
	t_info	info;

	input = take_off_parenthesis(cmd->argv[0]);
	envp = envlist_to_str(cmd->env);
	info.env = create_env_list(envp);
	set_and_execute(&info, input, cmd);
	del_word(&envp);
	free(input);
	exit(g_status);
}
