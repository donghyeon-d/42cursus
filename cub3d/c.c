/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:59:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/07 10:59:02 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20210621/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "cub3d.h"

// int	worldMap[24][24] = 
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,2,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,1},
// 	{1,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

int	worldMap[10][10] = 
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};


void	get_ray_diretion(t_info *info, t_ray *ray, int x)
{
	info->carmera_x = (x / (double)IMG_WID) - (1 / (double)2); // 0이면 화면의 중앙, -1/2이면 왼쪽 끝, 1/2이면 오른쪽 끝
	ray->rayDirX = info->dirX + info->planeX * info->carmera_x; // 광선 벡터 = 방향벡터 + 평면백터 * 평면벡터의 지점 (-1/2 ~ 1/2)
	ray->rayDirY = info->dirY + info->planeY * info->carmera_x;
	info->mapX = info->posX;
	info->mapY = info->posY;
}

void	get_delta_dist(t_info *info, t_ray *ray, int x)
{
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void	get_side_dist(t_info *info, t_ray *ray, int x)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		// ray->sideDistX = (info->posX - floor(info->posX)) * ray->deltaDistX; // floor 대신 map 으로 해야
		ray->sideDistX = (info->posX - info->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		// ray->sideDistX = (ceil(info->posX) - info->posX) * ray->deltaDistX;
		ray->sideDistX = (info->mapX + 1.0 - info->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		// ray->sideDistY = (info->posY - floor(info->posY)) * ray->deltaDistY;
		ray->sideDistY = (info->posY - info->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		// ray->sideDistY = (ceil(info->posY) - info->posY) * ray->deltaDistY;
		ray->sideDistY = (info->mapY + 1.0 - info->posY) * ray->deltaDistY;
	}
}

void	get_wall_dist(t_info *info, t_ray *ray)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->wallside = 0;
			// ray->wallDist = ray->sideDistX;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->wallside = 1;
			// ray->wallDist = ray->sideDistY;
		}
		if (worldMap[ray->mapY][ray->mapX] > 1)
			hit = 1;
	}
	if (ray->wallside == 0)
		ray->wallDist = (ray->mapX - info->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->wallDist = (ray->mapY - info->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
}

void	calc_dist_to_wall(t_ray *ray)
{
	ray->raydir = sqrt(pow(ray->rayDirX, 2) + pow(ray->rayDirY, 2));
	ray->wallDist = ray->wallDist / ray->raydir;
}

// 레이저로 거리 구하기
void	get_distance_to_wall(t_info *info, t_ray *ray, int x)
{
	int	stepX; // 1 이면 X 의 + 방향으로 감,  -1이면 - 방향으로 감
	int	stepY; // 1 이면 Y 의 + 방향으로 감,  -1이면 - 방향으로 감

	// info->carmera_x = (x / (double)WIN_WIDHT) - (1 / (double)2); // 0이면 화면의 중앙, -1/2이면 왼쪽 끝, 1/2이면 오른쪽 끝
	// ray->rayDirX = info->dirX + info->planeX * info->carmera_x; // 광선 벡터 = 방향벡터 + 평면백터 * 평면벡터의 지점 (-1/2 ~ 1/2)
	// ray->rayDirY = info->dirY + info->planeY * info->carmera_x;
	// ray->deltaDistX = fabs(1 / ray->rayDirX);

	get_ray_diretion(info, ray, x);
	get_delta_dist(info, ray, x);
	get_side_dist(info, ray, x);
	get_wall_dist(info, ray);
	calc_dist_to_wall(ray);
}

// 거리에 따른 높이 구하기
void	get_wall_height(t_info *info, t_ray *ray, int x)
{
	double dist_to_wall;

	get_distance_to_wall(info, ray, x);
	dist_to_wall = ray->wallDist;
	ray->line_height = IMG_HEI / dist_to_wall;
	ray->line_start = -dist_to_wall / 2 + IMG_HEI / 2;//(int)((IMG_HEI - ray->line_height) / 2);
	ray->line_end = +dist_to_wall / 2 + IMG_HEI / 2;//(int)((IMG_HEI - ray->line_height) / 2 + ray->line_height);
	if (ray->line_end >= IMG_HEI)
		ray->line_end = IMG_HEI - 1;
}
// 높이에 맞게 pixel 그리기


void	get_color(t_info *info, t_ray *ray)
{
	if (worldMap[ray->mapY][ray->mapX] == 1)
		ray->color = 0xFF0000;
	else if (worldMap[ray->mapY][ray->mapX] == 2)
		ray->color = 0x00FF00;
	else if (worldMap[ray->mapY][ray->mapX] == 3)
		ray->color = 0x0000FF;
	if (ray->wallside == 1)
		ray->color /= 2;
}


void	draw_vertical(t_info *info, t_ray *ray, int x)
{
	int i;

	i = -1;
	while (++i < ray->line_height)
		info->ad[x + (ray->line_start + i) * IMG_WID] = ray->color;
		// mlx_pixel_put(info->mlx, info->win, x, ray->line_start + i, ray->color);
}




int main()
{
	t_info *info;
	t_ray *ray;
	int x;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		exit(1);
	info->posX = 5;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->carmera_x = 0;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, IMG_WID, IMG_HEI, "cub3d");
	info->img = mlx_new_image(info->mlx, IMG_WID, IMG_HEI);
	info->ad = (int *)mlx_get_data_addr(info->img, &info->bpp, &info->len, &info->end);
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		exit(1);
	bzero(ray, sizeof(t_ray));
	ray->mapX = info->mapX;
	ray->mapY = info->mapY;
	x = -1;
	while (++x < IMG_WID)
	{
		get_wall_height(info, ray, x);
		get_color(info, ray);
		draw_vertical(info, ray, x);
		bzero(ray, sizeof(t_ray));
		ray->mapX = info->mapX;
		ray->mapY = info->mapY;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &ft_close_win, info);
	mlx_loop(info->mlx);
}
