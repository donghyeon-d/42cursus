/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:19:12 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 20:24:19 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "cub3d.h"

void	file_check(char *file)
{
	int	fd;

	if (file_check_type(file) == FALSE)
		error_exit("Wrong file name");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("can't open file");
	close(fd);
}