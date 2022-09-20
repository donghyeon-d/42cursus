/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:36:03 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/12 15:10:59 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"
#include "type.h"

void	heredoc_set_rdr(t_cmd *cmd, t_token *token)
{
	if (cmd == NULL || token == NULL || token->head->type != rdr)
		return ;
	if (ft_strsame("<<", token->head->token))
		rdr_set_herdoc_open(cmd, token);
}

void	heredoc_set(t_cmd *cmd, t_token *token)
{
	t_cmd	*tmp;

	if (cmd == NULL || token == NULL || token->cnt == 0)
		return ;
	tmp = cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	cmd_set_parenth(tmp, token);
	heredoc_set_rdr(tmp, token);
	cmd_set_link(tmp, token);
	cmd_set_argc(tmp, token);
	cmd_set_argv(tmp, token);
	if (tmp->link_type != null && tmp->argv != NULL && tmp->argv[0] != NULL)
	{
		tmp->next = create_cmd(tmp->env);
		cmd_set_num(cmd);
	}
}
