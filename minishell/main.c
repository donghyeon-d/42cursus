/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:49:00 by hhwang            #+#    #+#             */
/*   Updated: 2023/03/21 19:43:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

t_token	*parsing(char *input)
{
	t_token	*token;
	char	**word;

	word = split_input_to_word(input);
	token = word_to_token(word);
	del_word(&word);
	return (token);
}

void	setting(t_info *info)
{
	pid_t	pid;

	expanding(info->token, info->env);
	info->tree = make_token_tree(info->token);
	split_token_tree(info->tree->root);
	info->cmd = create_cmd(info->env);
	pid = fork();
	if (pid == 0)
	{
		set_signal(SIG_DFL, SIG_IGN);
		traversal_heredoc_set(info->tree->root, info->cmd);
		exit(g_status);
	}
	else if (pid > 0)
	{
		set_signal(SIG_IGN, SIG_IGN);
		wait_heredoc();
	}
	else
		exit(1);
	traversal_cmd_set(info->tree->root, info->cmd);
}

static void	set_and_execute(t_info *info, char *input)
{
	int	status;

	info->token = parsing(input);
	status = syntax_check(info->token);
	if (status == 0)
	{
		setting(info);
		if (g_status != -1)
			g_status = execute(info->cmd);
		else
			g_status = 1;
	}
	else
	{
		g_status = 258;
		write(2, "minishell: syntax error\n", 24);
	}
	unlink_tempfiles(info->cmd);
	del(&(info->tree), &(info->token), NULL, &(info->cmd));
	info->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_info	info;

	argc++;
	argv++;
	ft_memset(&info, 0, sizeof(t_info));
	info.env = create_env_list(envp);
	while (1)
	{
		set_signal(sigint_wait, SIG_IGN);
		set_term_echoctl(NO_ECHO);
		input = readline("minishell-3.2$ ");
		if (input == NULL)
		{
			printf("\033[1A\033[15Cexit\n");
			exit(g_status);
		}
		if (input[0] != '\0')
			add_history(input);
		if (input[0] != '\0' && ft_isempty(input) == 0)
			set_and_execute(&info, input);
		free(input);
	}
	del_env(&(info.env));
}
