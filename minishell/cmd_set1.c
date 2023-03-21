/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:38:55 by dongchoi          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "type.h"

void	cmd_set_argv(t_cmd *cmd, t_token *token)
{
	char			**argv;
	int				i;
	t_token_node	*temp;

	temp = token->head;
	if (cmd == NULL || token == NULL || token->head == NULL || \
	token->head->type > 3)
		return ;
	argv = malloc(sizeof(char *) * (token->cnt + 1));
	if (argv == NULL)
		exit(1);
	argv[token->cnt] = NULL;
	i = -1;
	while (++i < token->cnt)
	{
		argv[i] = ft_strdup(temp->token);
		temp = temp->next;
	}
	i = -1;
	while (++i < token->cnt)
		if (argv[i] == NULL)
			exit(1);
	cmd->argv = argv;
}

void	cmd_set_num(t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = cmd;
	tmp->num = i;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		++i;
		tmp->num = i;
	}
}

void	cmd_set_argc(t_cmd *cmd, t_token *token)
{
	if (cmd == NULL || token == NULL || token->head->type != words)
		return ;
	cmd->argc = token->cnt;
}

void	cmd_set(t_cmd *cmd, t_token *token)
{
	t_cmd	*tmp;

	if (cmd == NULL || token == NULL || token->cnt == 0)
		return ;
	tmp = cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	cmd_set_parenth(tmp, token);
	cmd_set_rdr(tmp, token);
	cmd_set_link(tmp, token);
	cmd_set_argc(tmp, token);
	cmd_set_argv(tmp, token);
	if (tmp->link_type != null && tmp->argv != NULL && tmp->argv[0] != NULL)
	{
		tmp->next = create_cmd(tmp->env);
		cmd_set_num(cmd);
	}
}

int	cmd_path_setting_cmd(t_cmd *cmd)
{
	char	*command;
	char	*word;

	if (cmd == NULL || cmd->argv == NULL || cmd->argv[0] == NULL)
		return (0);
	word = cmd->argv[0];
	if (is_builtin(word))
	{
		command = ft_strdup(word);
		cmd->is_builtin = TRUE;
	}
	else if (word[0] == '/' || \
	(ft_strlen(word) > 1 && word[0] == '.' && word[1] == '/') || \
	(ft_strlen(word) > 2 && word[0] == '.' && \
	word[1] == '.' && word[2] == '/'))
		command = ft_strdup(word);
	else
		command = cmd_expand(word, cmd->env);
	if (cmd->is_builtin == FALSE && cmd_valid_check(command) == FALSE)
	{
		free(command);
		return (0);
	}
	cmd->cmd = command;
	return (1);
}
