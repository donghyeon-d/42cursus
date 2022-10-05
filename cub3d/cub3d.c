#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cub3d.h"
#include "minilibx_mms_20210621/mlx.h"

int	worldMap[10][10] = 
{
	{3,2,2,2,2,2,2,2,2,2},
	{3,2,2,0,0,0,0,0,0,1},
	{3,0,0,0,0,0,0,0,0,1},
	{3,0,1,0,0,0,0,0,0,1},
	{3,0,0,0,0,0,0,0,0,1},
	{3,0,0,0,0,0,0,0,0,1},
	{3,0,2,0,0,0,3,3,3,1},
	{3,0,0,0,0,0,0,0,0,1},
	{3,0,0,0,0,0,0,0,0,1},
	{3,1,1,1,1,1,1,1,1,1}
};

void	make_map(t_info *info)
{
	info->worldmap = malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++)
	{
		(info->worldmap)[i] = malloc(sizeof(int) * 10);
		for (int j = 0; j < 10; j++)
		{
			info->worldmap[i][j] = worldMap[i][j];
		}
	}
}

void	print_all(t_info *info)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d ", info->worldmap[i][j]);
		printf("\n");
	}
}

void	screen_all(t_info *info, t_ray *ray)
{
	int	x;

	x = -1;
	while (++x < IMG_WID)
	{
		ft_get_distance_to_wall(info, ray, x);
		ft_get_wall_height(info, ray, x);
		ft_get_color(info, ray);
		ft_draw_vertical(info, ray, x);
		// verLine(info, x, ray->line_start, ray->line_end, ray->color);
		bzero(ray, sizeof(t_ray));
		ray->mapX = (int)(info->posX);
		ray->mapY = (int)(info->posY);
		ray->color = 0;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int	main()
{
	t_info	*info;
	t_ray	*ray;
	int		x;

	info = ft_create_info();
	info->posX = 5;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.2;
	info->map_hei = 10;
	info->map_wid = 10;
	ray = ft_create_ray(info);
	make_map(info);
	info->file = malloc(sizeof(char *) * 4);
	
	info->ray = ray;
	// print_all(info);
	screen_all(info, ray);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &ft_close_win, info);
	mlx_loop(info->mlx);
}