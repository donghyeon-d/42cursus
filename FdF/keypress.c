#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "c.h"

int	key_press(int keycode, t_data *img)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Z)
		img->env->distance += 10;
	else if (keycode == KEY_X)
		img->env->distance -= 10;
	ft_rotate_map(img->map, img->env);
	ft_draw_line_all(img->map, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	return (1);
}

int ft_close_win(void *param)
{
	exit(0);
}