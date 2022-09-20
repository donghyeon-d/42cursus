/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:39 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/14 18:40:21 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"
#include <stdlib.h>

int	option_check(char *line)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	if (line[i] == '-')
	{
		i++;
		while (line[i])
		{
			if (line[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	ft_echo(t_cmd *cmd)
{
	int	option;
	int	i;

	option = 0;
	i = 1;
	if (cmd->argv[1] != NULL)
	{
		if (option_check(cmd->argv[i]))
		{
			option = 1;
			i++;
			while (option_check(cmd->argv[i]))
				i++;
		}
		while (cmd->argv[i])
		{
			write(cmd->fd_out, cmd->argv[i], ft_strlen(cmd->argv[i]));
			if (cmd->argv[i + 1] != NULL)
				write(cmd->fd_out, " ", 1);
			i++;
		}
	}
	if (option == 0)
		write(cmd->fd_out, "\n", 1);
	return (0);
}
