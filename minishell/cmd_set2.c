/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:39:52 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 23:32:28 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"
#include "type.h"

void	cmd_set_parenth(t_cmd *cmd, t_token *token)
{
	if (cmd == NULL || token == NULL || token->head == NULL)
		return ;
	if (token->head->type != parenth)
		return ;
	cmd->is_parenthesis = TRUE;
}

void	cmd_set_rdr(t_cmd *cmd, t_token *token)
{
	if (cmd == NULL || token == NULL || token->head->type != rdr)
		return ;
	if (ft_strsame(">", token->head->token))
		rdr_set_stdout(cmd, token);
	else if (ft_strsame("<", token->head->token))
		rdr_set_stdin(cmd, token);
	else if (ft_strsame(">>", token->head->token))
		rdr_set_append(cmd, token);
	else if (ft_strsame("<<", token->head->token))
		rdr_set_herdoc(cmd);
}

void	cmd_set_link(t_cmd *cmd, t_token *token)
{
	if (cmd == NULL || token == NULL || token->head == NULL)
		return ;
	if (3 < token->head->type && token->head->type < 7)
		cmd->link_type = token->head->type;
}
