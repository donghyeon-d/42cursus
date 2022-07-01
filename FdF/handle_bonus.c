/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:27:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/01 15:28:31 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

static void	ft_draw_background(t_data *data)
{
	int	i;

	i = -1;
	while (++i < IMG_HEI * IMG_WID)
		data->ad[i] = 0x000000;
}

int ft_handle_map(t_data *data)
{
	ft_adj_map(data);
	ft_draw_background(data);
	ft_draw_line_all(data, data->map, WHITE);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}