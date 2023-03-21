/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:24:35 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

void	print_error_exit(t_error error)
{
	if (error == quote)
		write(2, "quote is not closed\n", 20);
	else if (error == parentheses)
		write(2, "parentheses is not closed\n", 26);
	else if (error == redirection)
		write(2, "bash: parse error near `\\n'\n", 27);
	else if (error == rdr_nofile)
		write(2, "bash: syntax error near unexpected token `newline'\n", 51);
	else if (error == nocmd)
	{
		g_status = 127;
		write(2, "minishell: command not found\n", 29);
	}
	else if (error == no_delimiter)
		write(2, "bash: syntax error near unexpected token\n", 41);
}

void	custom_error(t_cmd *cmd, char *line, int flag)
{
	write(2, "minishell: ", 11);
	write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
	write(2, ": ", 2);
	if (flag == 1)
	{
		write(2, cmd->argv[1], ft_strlen(cmd->argv[1]));
		write(2, ": ", 2);
	}
	write(2, line, ft_strlen(line));
	write(2, "\n", 1);
}
