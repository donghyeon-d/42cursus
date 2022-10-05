#include "cub3d.h"

static void	ft_draw_ceiling(t_info *info, t_ray *ray, int x)
{
	int	i;

	i = -1;
	if (info->dirX < 0)
		x = IMG_WID - x;
	while (++i < ray->line_start)
		(info->ad)[x + i * IMG_WID] = info->ceiling_color;
}

static void	ft_draw_floor(t_info *info, t_ray *ray, int x)
{
	int	i;

	i = ray->line_end;
	// if (x + i * IMG_WID > IMG_WID * IMG_HEI)
		// return ;
	if (info->dirX < 0)
		x = IMG_WID - x;
	while (++i < IMG_WID)
	{
		if (x + i * IMG_WID > IMG_WID * IMG_HEI)
			return ;
		(info->ad)[x + i * IMG_WID] = info->floor_color;
	}
}


static int	ft_get_wallside(t_info *info, t_ray *ray)
{
	// if (ray->wallside == 0) // x면
	// {
	// 	if (info->posY < ray->mapY)
	// 		return (SOUTH);
	// 	else
	// 		return (NORTH);
	// }
	// else // y면
	// {
	// 	if (info->posX < ray->mapX)
	// 		return (WEST);
	// 	else
	// 		return (EAST);
	// }

	if (ray->wallside == 0) // x면
	{
		if (info->dirY < 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else // y면
	{
		if (info->dirX < 0)
			return (WEST);
		else
			return (EAST);
	}
}

static void	ft_draw_wall(t_info *info, t_ray *ray, int x, int y)
{
	int	i;

	// i = ray->line_start - 1;
	if (info->dirX < 0)
		x = IMG_WID - x;
	// while (++i < ray->line_end)
	// {
		// if (x + i * IMG_WID > IMG_WID * IMG_HEI)
			// break ;
		(info->ad)[x + y * IMG_WID] = ray->color;
	// }
}

void	ft_draw_vertical(t_info *info, t_ray *ray, int x)
{
	int	wallside;
	int	color;
	int	y;

	ft_draw_ceiling(info, ray, x);
	wallside = ft_get_wallside(info, ray);
	y = ray->line_start - 1;
	while (++y < ray->line_end)
	{
		ray->color = ft_get_color(info, info->texture[wallside], x, y);
		ft_draw_wall(info, ray, x, y);
	}
	ft_draw_floor(info, ray, x);
}