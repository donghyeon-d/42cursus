/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/06 13:52:00 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf_bonus.h"

// int render_next_frame(t_data *img)
// {
// 	mlx_destroy_image(img->mlx, img->img);
// 	img->img = mlx_new_image(img->mlx, IMG_WID, IMG_HEI);
// 	img->ad = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
// 	ft_rotate_map(img->map, img->env);
// 	ft_draw_line_all(img->map, img);
// 	return (1);
// }

void	ft_string_put(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 50, 100, 0xFFFFFFF, "[KEY]");
	mlx_string_put(data->mlx, data->win, 50, 120, 0xFFFFFFF, "--- ROTATE ---");
	mlx_string_put(data->mlx, data->win, 50, 140, 0xFFFFFFF, "Z : rotate x++");
	mlx_string_put(data->mlx, data->win, 50, 160, 0xFFFFFFF, "X : rotate y++");
	mlx_string_put(data->mlx, data->win, 50, 180, 0xFFFFFFF, "C : rotate z++");
	mlx_string_put(data->mlx, data->win, 50, 200, 0xFFFFFFF, "A : rotate x--");
	mlx_string_put(data->mlx, data->win, 50, 220, 0xFFFFFFF, "S : rotate y--");
	mlx_string_put(data->mlx, data->win, 50, 240, 0xFFFFFFF, "D : rotate z--");

	mlx_string_put(data->mlx, data->win, 50, 300, 0xFFFFFFF, "--- ZOOM ---");
	mlx_string_put(data->mlx, data->win, 50, 320, 0xFFFFFFF, "+ : zoom in");
	mlx_string_put(data->mlx, data->win, 50, 340, 0xFFFFFFF, "- : zoom out");

	mlx_string_put(data->mlx, data->win, 50, 400, 0xFFFFFFF, "--- INIT ---");
	mlx_string_put(data->mlx, data->win, 50, 420, 0xFFFFFFF, "ENTER : initialization");
	
	mlx_string_put(data->mlx, data->win, 50, 480, 0xFFFFFFF, "--- ALTITUDE ---");
	mlx_string_put(data->mlx, data->win, 50, 500, 0xFFFFFFF, "Q : altitude++");
	mlx_string_put(data->mlx, data->win, 50, 520, 0xFFFFFFF, "W : altitude--");

	mlx_string_put(data->mlx, data->win, 50, 580, 0xFFFFFFF, "--- OFFSET ---");
	mlx_string_put(data->mlx, data->win, 50, 600, 0xFFFFFFF, "UP : offset_y++");
	mlx_string_put(data->mlx, data->win, 50, 620, 0xFFFFFFF, "DOWN : offset_y--");
	mlx_string_put(data->mlx, data->win, 50, 640, 0xFFFFFFF, "LEFT : offset_x--");
	mlx_string_put(data->mlx, data->win, 50, 660, 0xFFFFFFF, "RGHT : offset_x++");
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		write(1, "argument!!\n", 11);
		return (0);
	}
	data = ft_init_data(argv[1]);
	ft_handle_map(data);

	mlx_key_hook(data->win, &key_press, data);

	mlx_loop(data->mlx);
}
