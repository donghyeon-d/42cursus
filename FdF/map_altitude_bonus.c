/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_altitude_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:13 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/07 21:32:32 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf_bonus.h"
#include "./ft_libft/libft.h"

void	ft_adj_map_altitude(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
			data->map->table[i][j].z *= data->env->alt;
	}
}
