/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:15:14 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 22:35:00 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "cub3d.h"
#include "libft.h"

static int	read_buf_check(int buf_size, char *result)
{
	if (buf_size < 0)
		error_exit("read fail");
	else if (buf_size == 0 && !result[0])
	{
		free(result);
		return (FALSE);
	}
	else if (buf_size == 0)
		return (TRUE);
	return (-1);
}

char	*get_next_line(int fd)
{
	char	buf[2];
	int		buf_size;
	char	*temp;
	char	*result;
	int		flag;

	result = ft_malloc(sizeof(char));
	result[0] = '\0';
	buf[1] = '\0';
	while (!ft_strchr(result, '\n'))
	{
		buf_size = read(fd, buf, 1);
		flag = read_buf_check(buf_size, result);
		if (flag == TRUE)
			return (result);
		else if (flag == FALSE)
			return (NULL);
		temp = result;
		result = ft_strjoin(result, buf);
		if (!result)
			error_exit("malloc fail");
		free(temp);
	}
	return (result);
}
