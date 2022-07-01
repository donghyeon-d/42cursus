/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/01 15:28:16 by dongchoi         ###   ########.fr       */
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
	// mlx_expose_hook(img->win, &expose_handle, img);
	mlx_loop(data->mlx);
}
