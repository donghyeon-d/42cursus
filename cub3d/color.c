#include "cub3d.h"

void	ft_get_color(t_info *info, t_ray *ray)
{
	if ((info->worldmap)[ray->mapY][ray->mapX] == 1)
		ray->color = 0xFF0000;
	else if ((info->worldmap)[ray->mapY][ray->mapX] == 2)
		ray->color = 0x00FF00;
	else if ((info->worldmap)[ray->mapY][ray->mapX] == 3)
		ray->color = 0x0000FF;
	if (ray->wallside == 1)
		ray->color /= 2;
}