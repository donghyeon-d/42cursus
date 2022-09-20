/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:58:24 by hhwang            #+#    #+#             */
/*   Updated: 2022/09/12 19:01:36 by hhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "a.h"

int	is_numeric(char *str)
{
	char	**num;
	int		i;

	num = ft_split(str, ' ');
	if (num[1] != NULL)
		return (0);
	i = 0;
	while (num[0][i])
	{
		if (i == 0)
		{
			if (!ft_isdigit(num[0][i]) && num[0][i] != '-' && num[0][i] != '+')
				return (0);
		}
		else
		{
			if (!ft_isdigit(num[0][i]))
				return (0);
		}
		i++;
	}
	return (1);
}

void	exit_no_arg(void)
{
	write(2, "exit\n", 5);
	exit(g_status);
}

void	exit_one_arg(t_cmd *cmd)
{
	unsigned char	status;

	if (is_numeric(cmd->argv[1]))
	{
		status = (unsigned char)ft_atoi(cmd->argv[1]);
		write(2, "exit\n", 5);
		exit(status % 256);
	}
	else
	{
		status = 255;
		write(2, "exit\n", 5);
		custom_error(cmd, "numeric argument required", 1);
		exit(status);
	}
}

int	exit_many_arg(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (is_numeric(cmd->argv[i]))
	{
		write(2, "exit\n", 5);
		custom_error(cmd, "too many arguments", 0);
		return (1);
	}
	else
	{
		write(2, "exit\n", 5);
		custom_error(cmd, "numeric argument required", 1);
		exit(255);
	}
}

int	ft_exit(t_cmd *cmd)
{
	int	status;

	status = 0;
	if (cmd->argc == 1)
		exit_no_arg();
	else if (cmd->argc == 2)
		exit_one_arg(cmd);
	else
		status = exit_many_arg(cmd);
	return (status);
}
