/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:41:34 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/15 21:37:25 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type.h"
#include "a.h"

static void	replace_argv_with_home(t_cmd *cmd)
{
	char **argv;

	argv = malloc(sizeof(char *) * 3);
	if (argv == NULL)
		exit(1);
	argv[0] = ft_strdup(cmd->argv[0]);
	argv[1] = ft_getenv(cmd->env, "HOME");
	argv[2] = NULL;
	free(cmd->argv[0]);
	free(cmd->argv);
	cmd->argv = argv;
}

static char	*cd_path_setting(t_cmd *cmd)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (cmd->argv[1] == NULL)
	{
		replace_argv_with_home(cmd);
		new_pwd = ft_getenv(cmd->env, "HOME");
	}
	else if (ft_strsame("-", cmd->argv[1]))
	{
		new_pwd = ft_getenv(cmd->env, "OLDPWD");
		if (new_pwd == NULL)
			custom_error(cmd, "OLDPWD not set", 0);
		else
		{
			write(cmd->fd_out, new_pwd, ft_strlen(new_pwd));
			write(cmd->fd_out, "\n", 1);
		}
	}
	else if (ft_strsame("--", cmd->argv[1]))
		new_pwd = getcwd(NULL, 0);
	else
		new_pwd = ft_strdup(cmd->argv[1]);
	return (new_pwd);
}

static int	cd_pwd_export(t_cmd *cmd, char *old_pwd)
{
	char	*temp;
	char	*new_pwd;

	temp = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", temp);
	free(temp);
	temp = old_pwd;
	old_pwd = ft_strjoin("OLDPWD=", temp);
	free(temp);
	export_add_env(cmd, new_pwd);
	export_add_env(cmd, old_pwd);
	free(new_pwd);
	free(old_pwd);
	return (0);
}

int	ft_cd(t_cmd *cmd)
{
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = cd_path_setting(cmd);
	if (new_pwd == NULL)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (old_pwd == NULL)
		return (1);
	if (chdir((const char *)new_pwd) == -1)
	{
		custom_error(cmd, "no such file or directory", 1);
		free(new_pwd);
		free(old_pwd);
		return (1);
	}
	cd_pwd_export(cmd, old_pwd);
	free(new_pwd);
	return (0);
}
