/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_type_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:21:08 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
