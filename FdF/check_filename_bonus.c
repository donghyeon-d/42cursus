/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:41:25 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/11 10:05:40 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_check_filename(char *filename)
{
	char	*temp;

	if (filename == NULL || ft_strlen(filename) < 5)
		return (FALSE);
	temp = ft_strrchr(filename, '/');
	if (temp == NULL)
		temp = filename;
	else
		temp++;
	if (ft_strlen(temp) < 5 || (ft_strrncmp(temp, ".fdf", 4)))
		return (FALSE);
	return (TRUE);
}
