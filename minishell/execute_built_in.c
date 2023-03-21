/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:37:40 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_built_in_func(t_cmd *cmd)
{
	int	status;

	status = 1;
	if (ft_strsame(cmd->argv[0], "echo"))
		status = ft_echo(cmd);
	else if (ft_strsame(cmd->argv[0], "cd"))
		status = ft_cd(cmd);
	else if (ft_strsame(cmd->argv[0], "pwd"))
		status = ft_pwd(cmd);
	else if (ft_strsame(cmd->argv[0], "export"))
		status = ft_export(cmd);
	else if (ft_strsame(cmd->argv[0], "unset"))
		status = ft_unset(cmd);
	else if (ft_strsame(cmd->argv[0], "env"))
		status = ft_env(cmd);
	else if (ft_strsame(cmd->argv[0], "exit"))
		status = ft_exit(cmd);
	return (status);
}
