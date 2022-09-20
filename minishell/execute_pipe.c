/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:20:40 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:42:45 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "a.h"

static void	wait_cmd_pipe(t_cmd *cmd)
{
	int		status;
	int		signo;
	int		i;

	i = 0;
	while (wait(&status) != -1)
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
	unlink_tempfiles(cmd);
	set_signal(sigint_wait, SIG_IGN);
}

void	execute_pipe(t_cmd **cmd)
{
	t_cmd	*cmd_node;
	t_cmd	*prev_node;
	int		prev_in;

	prev_in = -1;
	cmd_node = *cmd;
	prev_node = cmd_node;
	while (cmd_node && prev_node->link_type == pipeline)
	{
		if (cmd_path_setting_cmd(cmd_node) == FALSE)
			break ;
		if (cmd_node->link_type == pipeline)
			pipe(cmd_node->pipe);
		execute_fork(cmd_node, prev_in);
		prev_in = cmd_node->pipe[0];
		prev_node = cmd_node;
		cmd_node = cmd_node->next;
	}
	close(prev_in);
	if (g_status != 126)
		wait_cmd_pipe(*cmd);
	*cmd = prev_node;
}
