#include <math.h>
#include "cub3d.h"

// ray->wallside
// ray->step


// int	ft_get_wallside(t_info *info, t_ray *ray)
// {
// 	if (ray->wallside == 0) // x면
// 	{
// 		if (info->posY < ray->mapY)
// 			return (SOUTH);
// 		else
// 			return (NORTH);
// 	}
// 	else // y면
// 	{
// 		if (info->posX < ray->mapX)
// 			return (WEST);
// 		else
// 			return (EAST);
// 	}
// }

int		ft_get_color(t_info *info, t_img *img, int x, int y)
{
	double wallX;
	double stepY;
	int texX;
	int	texY;
	int color;

	// ??
	if (info->ray->wallside == 0)
		wallX = info->posY + info->ray->wallDist * info->ray->rayDirY;
	else
		wallX = info->posX + info->ray->wallDist * info->ray->rayDirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)img->wid);
	if (info->ray->wallside == 0 && info->ray->rayDirX > 0)
		texX = img->wid - texX - 1;
	if (info->ray->wallside == 1 && info->ray->rayDirY < 0)
		texX = img->wid - texX - 1;
	// stepY = img->hei / info->ray->line_height;
	// texY = stepY * y;
	// color = img->ad[img->wid * texY + texX];

	double step = 1.0 * img->hei / info->ray->line_height;
	// Starting texture coordinate
	double texPos = (info->ray->line_start - IMG_HEI / 2 + info->ray->line_height / 2) * step;
	if (y != 0)
		texPos += step * y;
	texY = (int)texPos & (img->hei - 1);
	color = img->ad[img->wid * texY + texX];
	return (color);
}

// void	ft_get_color(t_info *info, t_ray *ray)
// {
// 	int	wallside;

// 	wallside = ft_get_wallside(info, ray);

	
// 	if ((info->worldmap)[ray->mapY][ray->mapX] == 1)
// 		ray->color = 0xFF0000;
// 	else if ((info->worldmap)[ray->mapY][ray->mapX] == 2)
// 		ray->color = 0x00FF00;
// 	else if ((info->worldmap)[ray->mapY][ray->mapX] == 3)
// 		ray->color = 0x0000FF;
// 	if (ray->wallside == 1)
// 		ray->color /= 2;
// }