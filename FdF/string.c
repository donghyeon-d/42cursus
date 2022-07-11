/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:10:19 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/09 16:22:52 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20210621/mlx.h"
#include "fdf.h"

void	ft_string_put(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 50, 80, 0xFFFFFFF, "    [KEY]");
	mlx_string_put(data->mlx, data->win, 50, 120, 0xFFFFFFF, "---ROTATE---");
	mlx_string_put(data->mlx, data->win, 50, 140, 0xFFFFFFF, "Z : direct x++");
	mlx_string_put(data->mlx, data->win, 50, 160, 0xFFFFFFF, "X : direct y++");
	mlx_string_put(data->mlx, data->win, 50, 180, 0xFFFFFFF, "C : direct z++");
	mlx_string_put(data->mlx, data->win, 50, 200, 0xFFFFFFF, "A : direct x--");
	mlx_string_put(data->mlx, data->win, 50, 220, 0xFFFFFFF, "S : direct y--");
	mlx_string_put(data->mlx, data->win, 50, 240, 0xFFFFFFF, "D : direct z--");
	mlx_string_put(data->mlx, data->win, 50, 300, 0xFFFFFFF, "---ZOOM---");
	mlx_string_put(data->mlx, data->win, 50, 320, 0xFFFFFFF, "+ : zoom in");
	mlx_string_put(data->mlx, data->win, 50, 340, 0xFFFFFFF, "- : zoom out");
	mlx_string_put(data->mlx, data->win, 50, 400, 0xFFFFFFF, "---INIT---");
	mlx_string_put(data->mlx, data->win, 50, 420, 0xFFFFFFF, "I : initial");
	mlx_string_put(data->mlx, data->win, 50, 440, 0xFFFFFFF, "O : upside");
	mlx_string_put(data->mlx, data->win, 50, 460, 0xFFFFFFF, "P : parallel");
	mlx_string_put(data->mlx, data->win, 50, 520, 0xFFFFFFF, "---ALTITUDE---");
	mlx_string_put(data->mlx, data->win, 50, 540, 0xFFFFFFF, "Q : altitude++");
	mlx_string_put(data->mlx, data->win, 50, 560, 0xFFFFFFF, "W : altitude--");
	mlx_string_put(data->mlx, data->win, 50, 620, 0xFFFFFFF, "---OFFSET---");
	mlx_string_put(data->mlx, data->win, 50, 640, 0xFFFFFFF, "UP : ofs_y++");
	mlx_string_put(data->mlx, data->win, 50, 660, 0xFFFFFFF, "DOWN : ofs_y--");
	mlx_string_put(data->mlx, data->win, 50, 680, 0xFFFFFFF, "LEFT : ofs_x--");
	mlx_string_put(data->mlx, data->win, 50, 700, 0xFFFFFFF, "RGHT : ofs_x++");
}
