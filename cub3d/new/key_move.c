#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "cub3d.h"

void	ft_move_return(t_info *info, int key)
{
	if (key == KEY_W)
	{
		info->posX -= info->dirX * info->moveSpeed * 2;
		info->posY -= info->dirY * info->moveSpeed * 2;
	}
	else if (key == KEY_S)
	{
		info->posX += info->dirX * info->moveSpeed * 2;
		info->posY += info->dirY * info->moveSpeed * 2;
	}
	else if (key == KEY_A)
	{
		info->posX -= info->planeX * info->moveSpeed * 2;
		info->posY -= info->planeY * info->moveSpeed * 2;
	}
	else if (key == KEY_D)
	{
		info->posX += info->planeX * info->moveSpeed * 2;
		info->posY += info->planeY * info->moveSpeed * 2;
	}
}

static double	ft_rotate_clock(t_info *info, double angle)
{
	int	dir_x;
	int	plane_x;
	t_info	tmp;
	t_ray	tmp_ray;

	tmp = *info;
	tmp_ray = *(info->ray);
	if (angle != 0)
	{
		dir_x = tmp.dirX;
		plane_x = tmp.planeX;
		tmp.dirX = dir_x * cos(angle) - tmp.dirY * sin(angle);
		tmp.dirY = tmp.dirY * cos(angle) + dir_x * sin(angle);
		tmp.planeX = fabs(plane_x * cos(angle) - tmp.planeY * sin(angle));
		tmp.planeY = fabs(tmp.planeY * cos(angle) + plane_x * sin(angle));
	}
	ft_get_distance_to_wall(&tmp, &tmp_ray, IMG_WID / 2);
	return (tmp_ray.wallDist);
}


static int	ft_can_move_check(t_info *info, int key)
{
	double	min;
	double	compare;
	int		x;
	int		y;
	int		i;

	x = (int)(info->posX);
	y = (int)(info->posY);
	i = -1;
	min = 10000000;
	while (++i < 4)
	{
		compare = ft_rotate_clock(info, i);
		if (min > compare)
			min = compare;
	}
	printf("min : %f\n", min);
	if (min < 0.2)
		return (FALSE);
	else
		return (TRUE);
}

void	ft_key_move(int key, t_info *info)
{
	if (key == KEY_W)
	{
		info->posX += info->dirX * info->moveSpeed;
		info->posY += info->dirY * info->moveSpeed;
	}
	else if (key == KEY_S)
	{
		info->posX -= info->dirX * info->moveSpeed;
		info->posY -= info->dirY * info->moveSpeed;
	}
	else if (key == KEY_A)
	{
		info->posX += info->planeX * info->moveSpeed;
		info->posY += info->planeY * info->moveSpeed;
	}
	else if (key == KEY_D)
	{
		info->posX -= info->planeX * info->moveSpeed;
		info->posY -= info->planeY * info->moveSpeed;
	}
	if (ft_can_move_check(info, key) == FALSE)
		ft_move_return(info, key);
	screen_all(info, info->ray);
}
