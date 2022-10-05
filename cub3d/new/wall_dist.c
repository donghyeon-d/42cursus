#include <math.h>
#include "cub3d.h"

static void	ft_calc_ray_diretion(t_info *info, t_ray *ray, int x)
{
	// info->carmera_x = (x / (double)IMG_WID) - (1 / (double)2); // 0이면 화면의 중앙, -1/2이면 왼쪽 끝, 1/2이면 오른쪽 끝
	info->carmera_x = 2 * x / (double)IMG_WID - 1; // 0이면 화면의 중앙, -1/2이면 왼쪽 끝, 1/2이면 오른쪽 끝
	ray->rayDirX = info->dirX + info->planeX * info->carmera_x; // 광선 벡터 = 방향벡터 + 평면백터 * 평면벡터의 지점 (-1/2 ~ 1/2)
	ray->rayDirY = info->dirY + info->planeY * info->carmera_x;
	ray->mapX = (int)info->posX;
	ray->mapY = (int)info->posY;
}


static void	ft_calc_delta_dist(t_info *info, t_ray *ray)
{
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}

static void	ft_calc_get_side_dist(t_info *info, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		// ray->sideDistX = (info->posX - floor(info->posX)) * ray->deltaDistX; // floor 대신 map 으로 해야
		ray->sideDistX = (info->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		// ray->sideDistX = (ceil(info->posX) - info->posX) * ray->deltaDistX;
		ray->sideDistX = (ray->mapX + 1.0 - info->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		// ray->sideDistY = (info->posY - floor(info->posY)) * ray->deltaDistY;
		ray->sideDistY = (info->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		// ray->sideDistY = (ceil(info->posY) - info->posY) * ray->deltaDistY;
		ray->sideDistY = (ray->mapY + 1.0 - info->posY) * ray->deltaDistY;
	}
}

static void	ft_calc_wall_dist(t_info *info, t_ray *ray)
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
		if ((info->worldmap)[ray->mapY][ray->mapX] > 0)
			hit = 1;
	}
	if (ray->wallside == 0)
		ray->wallDist = (ray->mapX - info->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->wallDist = (ray->mapY - info->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
}

void	ft_get_distance_to_wall(t_info *info, t_ray *ray, int x)
{
	ft_calc_ray_diretion(info, ray, x);
	ft_calc_delta_dist(info, ray);
	ft_calc_get_side_dist(info, ray);
	ft_calc_wall_dist(info, ray);
}