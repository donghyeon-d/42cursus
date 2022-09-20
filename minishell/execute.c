/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:20:40 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/16 11:19:38 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "a.h"

void	wait_cmd(t_cmd *cmd)
{
	int		status;
	int		signo;
	int		i;

	i = 0;
	if (waitpid(cmd->pid, &status, 0) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT && i++ == 0)
				write(2, "^C\n", 3);
			else if (signo == SIGQUIT && i++ == 0)
				write(2, "^\\Quit: 3\n", 10);
			if (signo == SIGINT || signo == SIGQUIT)
				g_status = 128 + signo;
			else
				g_status = 127;
		}
		else
			g_status = WEXITSTATUS(status);
	}
	set_signal(sigint_wait, SIG_IGN);
}

int	execute(t_cmd *cmd)
{
	t_cmd	*cmd_node;
	t_cmd	*prev_cmd;

	cmd_node = cmd;
	prev_cmd = cmd_node;
	while (cmd_node)
	{
		if (cmd_node->num != 0 && prev_cmd->link_type == and)
			execute_and(&cmd_node);
		else if (cmd_node->num != 0 && prev_cmd->link_type == or)
			execute_or(&cmd_node);
		else if (cmd_node->link_type == pipeline)
			execute_pipe(&cmd_node);
		else
			execute_single(cmd_node);
		prev_cmd = cmd_node;
		cmd_node = cmd_node->next;
	}
	unlink_tempfiles(cmd);
	return (g_status);
}
