#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "c.h"

void	ft_draw_line(t_data *img, t_pos from, t_pos to, int distance)
{
	int	x;
	int	y;
	int	z;
	int	i;
	int inc;

	// inc = (to.y - from.y) / (to.x - from.x);

	x = from.x - 1;
	y = from.y - 1;
	while (++x < to.x * distance)
	{
		img->addr[x] = 0xFFFFFF;
		i = - 1;
		// while (++i < distance)
	}

}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = (int*)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// for (int i = 0; i)
	
	t_pos start = {0, 0, 0};
	t_pos end = {10, 10, 0};
	ft_draw_line(&img, start, end, 3);
	// int count_h = -1;
	// int count_w;
	// while (++count_h < IMG_HEIGHT)
	// {
		
	// 	count_w = -1;
	// 	while (++count_w < IMG_WIDTH)
	// 	{
	// 		if (count_w % 2)
	// 			img.addr[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
	// 		else
	// 			img.addr[count_h * IMG_WIDTH + count_w] = 0xFF0000;
	// 	}
	// }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_loop(mlx);
}