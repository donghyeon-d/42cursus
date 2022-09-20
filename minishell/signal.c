/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhwang <hhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:44:17 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 19:06:48 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <term.h>
#include <readline/readline.h>
#include "a.h"

void	rl_replace_line(const char *text, int clear_undo);

void	sigint_wait(int num)
{
	num++;
	g_status = 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	set_term_echoctl(int flag)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	if (flag)
		term.c_lflag &= ~(ECHOCTL);
	else
		term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	set_signal(void (*sig_int)(int), void (*sig_quit)(int))
{
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_quit);
}
