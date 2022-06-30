/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 19:05:05 by dongchoi         ###   ########.fr       */
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

t_env	*init_env(void)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	new_env->angle_radian = 0.7;
	new_env->alpha = -0.7;
	new_env->distance = 50;
	new_env->altitude = 4;
	new_env->x_min = 2147483647;
	new_env->y_min = 2147483647;
	return (new_env);
}

t_data	*ft_data_init(char *map_file)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		exit(1);
	d->env = init_env();
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, IMG_WID, IMG_HEI, "FdF");
	d->img = mlx_new_image(d->mlx, IMG_WID, IMG_HEI);
	d->ad = (int *)mlx_get_data_addr(d->img, &d->bpp, &d->len, &d->end);
	d->map_file = map_file;
	return (d);
}

int expose_handle(t_data *img)
{
	ft_rotate_map(img->map, img->env);
	ft_draw_line_all(img->map, img, 0xFFFFFF);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	*img;

	if (argc != 2)
	{
		write(1, "argument!!\n", 11);
		return (0);
	}
	img = ft_data_init(argv[1]);
	img->map = make_map(img->map_file);
	expose_handle(img);
	// ft_rotate_map(img->map, img->env);
	// ft_draw_line_all(img->map, img);
	// mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	// mlx_hook(img->win, X_EVENT_KEY_PRESS, 1L<<0, key_press, (t_data *)img);
	// mlx_hook(img->win, X_EVENT_KEY_EXIT, 0, ft_close_win, (t_data *)img);

	mlx_key_hook(img->win, &key_press, img);
	// mlx_expose_hook(img->win, &expose_handle, img);
	mlx_loop(img->mlx);
}
