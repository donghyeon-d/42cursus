/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:47:41 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 11:29:22 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"

int	key_press(int keycode, t_data *img)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Z)
		img->env->distance += 1;
	else if (keycode == KEY_X)
		img->env->distance -= 1;
	ft_rotate_map(img->map, img->env);
	ft_draw_line_all(img->map, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	return (1);
}

int	ft_close_win(void *param)
{
	exit(0);
	param = (char *)0;
}
