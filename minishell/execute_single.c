/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:22:44 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:30:53 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"

int	execute_single(t_cmd *cmd)
{
	if (cmd_path_setting_cmd(cmd) == FALSE)
		return (g_status);
	if (cmd->next == NULL && cmd->is_builtin == TRUE)
		g_status = execute_built_in_func(cmd);
	else
		execute_fork(cmd, -1);
	if (g_status != 126)
		wait_cmd(cmd);
	return (g_status);
}
