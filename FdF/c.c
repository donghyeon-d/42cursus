#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "c.h"

t_env *init_env(void)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	new_env->angle_radian = 0.7;
	new_env->alpha = -0.5;
	new_env->distance = 60;
	new_env->altitude = 4;
	new_env->x_min = 2147483647;
	new_env->y_min = 2147483647;
	return (new_env);
}

void display_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("{%d %d %d} ", map->map_table[i][j].x, map->map_table[i][j].y, map->map_table[i][j].z);
		printf("\n");
	}
}

void	ft_add_distance(t_map *map, int distance)
{
	int	i;
	int	j;

	i = -1;
	while (i < map->height)
	{
		while (j < map->width)
		{
			map->map_table[i][j].x *= distance;
			map->map_table[i][j].y *= distance;
			map->map_table[i][j].z *= distance;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	*img;
	// t_map	*map;
	// t_env	*env;

	// map = make_map(argv[1]);
	if (argc != 2)
	{
		write(1, "argument!!\n", 11);
		return (0);
	}
	img = malloc(sizeof(t_data));
	img->env = init_env();
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, IMG_WIDTH, IMG_HEIGHT, "Hello world!");
	img->img = mlx_new_image(img->mlx, IMG_WIDTH, IMG_HEIGHT);
	img->addr = (int*)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->map = make_map(argv[1]);
	display_map(img->map);
	printf("\n\n");
	ft_rotate_map(img->map, img->env);
	display_map(img->map);
	ft_draw_line_all(img->map, img);

	mlx_put_image_to_window(img->mlx, img->win, img->img, 100, 100);
	mlx_hook(img->win, X_EVENT_KEY_RELEASE, 0, key_press, (t_data *)img);
	mlx_hook(img->win, X_EVENT_KEY_EXIT, 0, ft_close_win, (t_data *)img);
	mlx_loop(img->mlx);
}