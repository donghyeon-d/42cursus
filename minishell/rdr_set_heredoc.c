/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_set_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:17:24 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 23:21:09 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "a.h"
#include <signal.h>
#include <sys/wait.h>

void	wait_heredoc(void)
{
	int		status;
	int		signo;

	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT)
			{
				write(2, ">\n", 2);
				g_status = -1;
			}
		}
	}
}

void	rdr_set_herdoc(t_cmd *cmd)
{
	rdr_set_herdoc_read(cmd);
}

void	rdr_set_herdoc_open(t_cmd *cmd, t_token *token)
{
	char	*herdoc;
	char	*buf;
	int		fd;
	char	filename[17];

	set_signal(SIG_DFL, SIG_IGN);
	herdoc = token->head->next->token;
	ft_strcpy(filename, "/tmp/minishell_a");
	filename[15] += cmd->num;
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	buf = readline("> ");
	while (buf != NULL && !ft_strsame(buf, herdoc))
	{
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
		buf = readline("> ");
	}
	free(buf);
	close(fd);
}

void	rdr_set_herdoc_read(t_cmd *cmd)
{
	int		fd;
	char	filename[17];

	ft_strcpy(filename, "/tmp/minishell_a");
	filename[15] += cmd->num;
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	fd = open(filename, O_RDWR, 0644);
	cmd->fd_in = fd;
}
