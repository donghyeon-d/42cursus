/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/04 20:38:50 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <mlx.h>
#include "./minilibx/mlx.h"
#include "fdf.h"

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

t_data	*ft_data_init(void)
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
	return (d);
}

int	main(int argc, char *argv[])
{
	t_data	*img;

	if (argc != 2)
	{
		write(1, "argument!!\n", 11);
		return (0);
	}
	img = ft_data_init();
	img->map = make_map(argv[1], img->env);
	ft_rotate_map(img->map, img->env);
	ft_draw_line_all(img->map, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	mlx_hook(img->win, X_EVENT_KEY_RELEASE, 0, key_press, (t_data *)img);
	mlx_hook(img->win, X_EVENT_KEY_EXIT, 0, ft_close_win, (t_data *)img);
	mlx_loop(img->mlx);
}
