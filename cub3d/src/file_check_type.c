/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:21:08 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/13 19:32:53 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_check_type(char *filename)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (filename[len - 1] != 'b' || \
	filename[len - 2] != 'u' || \
	filename[len - 3] != 'c' || \
	filename[len - 4] != '.')
		return (FALSE);
	return (TRUE);
}
