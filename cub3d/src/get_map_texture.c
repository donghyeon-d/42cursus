/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:40:39 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 11:46:59 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_texture(int fd, char **line, t_info *info)
{
	if (what_info(*line) != MAP_TEXTURE)
		return ;
	while ((*line)[0] != '\n')
	{
		if (!ft_strncmp(*line, "NO ", 3) && !info->texture_file[NORTH])
			info->texture_file[NORTH] = ft_strdup(&((*line)[3]));
		else if (!ft_strncmp(*line, "EA ", 3) && !info->texture_file[EAST])
			info->texture_file[EAST] = ft_strdup(&((*line)[3]));
		else if (!ft_strncmp(*line, "SO ", 3) && !info->texture_file[SOUTH])
			info->texture_file[SOUTH] = ft_strdup(&((*line)[3]));
		else if (!ft_strncmp(*line, "WE ", 3) && !info->texture_file[WEST])
			info->texture_file[WEST] = ft_strdup(&((*line)[3]));
		else
			error_exit("TEXTURE Map informations are not seperated");
		free(*line);
		*line = get_next_line(fd);
		if (*line == NULL)
			error_exit("Map need more infomations");
	}
	pass_newline(fd, line);
}
