/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:40:11 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/12 16:35:46 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"
#include "type.h"

t_cmd	*create_cmd(t_env *env)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (new == NULL)
		exit(1);
	new->num = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->cmd = NULL;
	new->argc = 1;
	new->argv = NULL;
	new->env = env;
	new->link_type = null;
	new->pipe[0] = -1;
	new->pipe[1] = -1;
	new->pid = 0;
	new->status = 0;
	new->is_builtin = FALSE;
	new->is_parenthesis = FALSE;
	new->next = NULL;
	return (new);
}

int	is_builtin(char *word)
{
	if (word == NULL)
		return (0);
	if (ft_strsame(word, "echo") || ft_strsame(word, "cd") || \
	ft_strsame(word, "pwd") || ft_strsame(word, "export") || \
	ft_strsame(word, "unset") || ft_strsame(word, "env") || \
	ft_strsame(word, "exit"))
		return (1);
	else
		return (0);
}

void	del_cmd(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*del;

	temp = *cmd;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		free(del->cmd);
		del_word(&(del->argv));
		free(del);
	}
	*cmd = NULL;
}
