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


static void	ft_draw_wall(t_info *info, t_ray *ray, int x)
{
	int	i;
	
	i = ray->line_start - 1;
	if (info->dirX < 0)
		x = IMG_WID - x;
	while (++i < ray->line_end)
	{
		// if (x + i * IMG_WID > IMG_WID * IMG_HEI)
			// break ;
		(info->ad)[x + i * IMG_WID] = ray->color;
	}
}

void	ft_draw_vertical(t_info *info, t_ray *ray, int x)
{
	ft_draw_ceiling(info, ray, x);
	// ft_draw_floor(info, ray, x);
	ft_draw_wall(info, ray, x);
}