/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:21:13 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/13 21:08:21 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	ft_raycasting(t_info *info)
{
	int	x;

	x = -1;
	while (++x < WIN_WID)
	{
		init_ray(info, &(info->ray), x);
		start_dda(info, &(info->ray));
		take_wall_point(info, &(info->ray));
		draw_line(info, &(info->ray), x);
		if (info->ray.door_lst)
			ft_lstclear(&info->ray.door_lst, free);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->screen_img.img, 0, 0);
	ft_minimap(info);
	return (0);
}
