#include "cub3d.h"

void	ft_get_wall_height(t_info *info, t_ray *ray, int x)
{
	double dist_to_wall;

	dist_to_wall = ray->wallDist;
	ray->line_height = (int)(IMG_HEI / dist_to_wall);
	ray->line_start = (IMG_HEI - dist_to_wall) / 2;
	// ray->line_start = -dist_to_wall / 2 + IMG_HEI / 2;//(int)((IMG_HEI - ray->line_height) / 2);
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = ray->line_start + ray->line_height;
	// ray->line_end = dist_to_wall / 2 + IMG_HEI / 2;//(int)((IMG_HEI - ray->line_height) / 2 + ray->line_height);
	if (ray->line_end >= IMG_HEI)
		ray->line_end = IMG_HEI - 1;
}