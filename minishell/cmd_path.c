/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:43:06 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/14 18:41:33 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "a.h"
#include "type.h"

int	cmd_valid_check(char *cmd_with_path)
{
	struct stat	file_stat;

	if (cmd_with_path == NULL)
		return (1);
	if (stat(cmd_with_path, &file_stat) < 0)
		return (1);
	if (!(file_stat.st_mode & S_IFREG) || \
	!(file_stat.st_mode & S_IXOTH))
	{
		if (!(file_stat.st_mode & S_IFREG))
			write(2, "minishell: is a directory\n", 26);
		else if (!(file_stat.st_mode & S_IXOTH))
			write(2, "minishell: permission denied\n", 29);
		g_status = 126;
		return (0);
	}
	else
		return (1);
}

char	*cmd_expand(char *cmd, t_env *env_list)
{
	char	**path;
	char	*env_value;
	char	*ret;
	int		i;

	env_value = ft_getenv(env_list, "PATH");
	if (env_value == NULL)
		env_value = ft_strdup("./");
	path = ft_split(env_value, ':');
	ret = NULL;
	i = -1;
	while (path[++i] != NULL)
	{
		if (file_name_check(cmd, path[i]))
		{
			ret = ft_strjoin_with_c(path[i], cmd, '/');
			if (file_exec_check(ret))
				break ;
			free(ret);
			ret = NULL;
		}
	}
	del_word(&path);
	free(env_value);
	return (ret);
}

int	file_name_check(char *cmd, char *path)
{
	DIR				*dir_fd;
	struct dirent	*dir_info;

	dir_fd = opendir((const char *)path);
	if (dir_fd == NULL)
		return (FALSE);
	dir_info = readdir(dir_fd);
	while (dir_info != NULL)
	{
		if (ft_strsame(cmd, dir_info->d_name))
		{
			closedir(dir_fd);
			return (TRUE);
		}
		dir_info = readdir(dir_fd);
	}
	closedir(dir_fd);
	return (FALSE);
}

int	file_exec_check(char *cmd_path)
{
	struct stat	file_stat;

	if (cmd_path == NULL)
		return (FALSE);
	if (stat(cmd_path, &file_stat) < 0)
		return (FALSE);
	if (!(file_stat.st_mode & S_IFREG) || \
	!(file_stat.st_mode & S_IXOTH))
	{
		if (!(file_stat.st_mode & S_IFREG))
			write(2, "minishell: is a directory\n", 26);
		else if (!(file_stat.st_mode & S_IXOTH))
			write(2, "minishell: permission denied\n", 29);
		g_status = 126;
		return (FALSE);
	}
	else
		return (TRUE);
}
