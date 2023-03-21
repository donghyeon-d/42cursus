/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:21:24 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

void	rdr_set_stdin(t_cmd *cmd, t_token *token)
{
	char	*file;
	int		fd_in;

	if (cmd == NULL || token == NULL || token->head == NULL)
		return ;
	if (!ft_strsame("<", token->head->token) || token->cnt != 2)
		return ;
	file = token->head->next->token;
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	fd_in = open(file, O_RDONLY, 0644);
	if (fd_in == -1)
	{
		if (g_status != -1)
			write(2, "minishell: No such file or directory\n", 37);
		g_status = -1;
		return ;
	}
	cmd->fd_in = fd_in;
}

void	rdr_set_stdout(t_cmd *cmd, t_token *token)
{
	char	*file;
	int		fd_out;

	if (cmd == NULL || token == NULL || token->head == NULL)
		return ;
	if (!ft_strsame(">", token->head->token) || token->cnt != 2)
		return ;
	file = token->head->next->token;
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd->fd_out = fd_out;
}

void	rdr_set_append(t_cmd *cmd, t_token *token)
{
	char	*file;
	int		fd_out;

	if (cmd == NULL || token == NULL || token->head == NULL)
		return ;
	if (!ft_strsame(">>", token->head->token) || token->cnt != 2)
		return ;
	file = token->head->next->token;
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->fd_out = fd_out;
}
