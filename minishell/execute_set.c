/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:43:49 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "a.h"

void	close_cmd_fd(t_cmd *cmd)
{
	if (cmd->pipe[0] != 0)
		close(cmd->pipe[0]);
	if (cmd->pipe[1] != 1)
		close(cmd->pipe[1]);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
}

void	unlink_tempfiles(t_cmd *cmd)
{
	char	filename[17];

	while (cmd)
	{
		close_cmd_fd(cmd);
		ft_strcpy(filename, "/tmp/minishell_a");
		filename[15] += cmd->num;
		unlink(filename);
		cmd = cmd->next;
	}
}
