/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:42:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 22:58:35 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static void	del_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int	ft_stoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			error_exit("invalid color");
		result *= 10;
		result += str[i] - '0';
	}
	return (result);
}

static int		color_parse(char *line)
{
	char	**str;
	int		color;

	str = ft_split(line, ',');
	if (!str)
		error_exit("malloc fail");
	if (str[0] == NULL || str[1] == NULL || str[2] == NULL || str[3] != NULL)
		error_exit("Wrong color information");
	str[2][ft_strlen(str[2]) - 1] = '\0';
	color = (ft_stoi(str[0]) << 8) + (ft_stoi(str[1]) << 4) + ft_stoi(str[2]);
	del_str(str);
	return (color);
}

void	get_map_color(int fd, char **line, t_info *info)
{
	if (what_info(*line) != MAP_COLOR)
		return ;
	while ((*line)[0] != '\n')
	{
		// printf("%s", *line);
		if (!ft_strncmp(*line, "F " , 2))
			info->floor_color = color_parse(&(*line)[2]);
		else if (!ft_strncmp(*line, "C " , 2))
			info->ceiling_color = color_parse(&((*line)[2]));
		else
			error_exit("COLOR Map informations are not seperated");
		free(*line);
		*line = get_next_line(fd);
		if (*line == NULL)
			error_exit("Wrong map");
	}
	pass_newline(fd, line);
}