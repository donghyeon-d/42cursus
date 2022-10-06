/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:45:09 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 20:37:06 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "cub3d.h"

int		what_info(char *line)
{
	if (line == NULL)
		return (FALSE);
	if (!ft_strncmp(line, "NO " , 3) || !ft_strncmp(line, "EA " , 3) || \
		!ft_strncmp(line, "SO " , 3) || !ft_strncmp(line, "WE " , 3))
		return (MAP_TEXTURE);
	else if (!ft_strncmp(line, "F " , 2) || !ft_strncmp(line, "C " , 2))
		return (MAP_COLOR);
	else
		return (MAP_MAP);
}

void	pass_newline(int fd, char **line)
{
	if ((*line)[0] != '\n')
		return ;
	while ((*line)[0] == '\n')
	{
		free(*line);
		*line = get_next_line(fd);
		if (*line == NULL)
			error_exit("Wrong map");
	}
}

void	get_map_info(char *file, t_info *info)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (what_info(line) != MAP_MAP)
	{
		get_map_texture(fd, &line, info);
		get_map_color(fd, &line, info);
	}
	get_map(fd, line, info);
	// map_check(info->worldmap);
	close(fd);
}