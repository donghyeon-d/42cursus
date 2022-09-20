/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_and_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:34:57 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:39:51 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"

void	execute_and(t_cmd **cmd)
{
	if (g_status != 0)
		return ;
	if ((*cmd)->link_type == pipeline)
		execute_pipe(cmd);
	else
		execute_single(*cmd);
}

void	execute_or(t_cmd **cmd)
{
	if (g_status == 0)
		return ;
	if ((*cmd)->link_type == pipeline)
		execute_pipe(cmd);
	else
		execute_single(*cmd);
}
