#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "cub3d.h"

int	ft_close_win(void)
{
	exit(0);
	return (0);
}

void	ft_key_rotate(int key, t_info *info)
{
	double	x;
	double plane_x;

	x = info->dirX;
	plane_x = info->planeX;
	if (key == KEY_LEFT)
	{
		info->dirX = x * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = info->dirY * cos(info->rotSpeed) + x * sin(info->rotSpeed);
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = plane_x * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	else if (key == KEY_RIGHT)
	{
		info->dirX = info->dirX * cos(info->rotSpeed) + info->dirY * sin(info->rotSpeed);
		info->dirY = info->dirY * cos(info->rotSpeed) - x * sin(info->rotSpeed);
		info->planeX = info->planeX * cos(info->rotSpeed) + info->planeY * sin(info->rotSpeed);
		info->planeY = info->planeY * cos(info->rotSpeed) - plane_x * sin(info->rotSpeed);
	}
	screen_all(info, info->ray);
}

void	ft_key_movespeed(int key, t_info *info)
{
	if (key == KEY_P && info->moveSpeed > 0.2)
		info->moveSpeed -= 0.05;
	else if(key == KEY_O && info->moveSpeed < 1)
		info->moveSpeed += 0.05;
}

void	ft_key_rotatespeed(int key, t_info *info)
{
	if (key == KEY_K && info->rotSpeed > 0.2)
		info->rotSpeed -= 0.05;
	else if (key == KEY_L && info->rotSpeed < 1)
		info->rotSpeed += 0.05;
}

int	ft_key_press(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W)
		ft_key_move(key, info);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		ft_key_rotate(key, info);
	else if (key == KEY_P || key == KEY_O)
		ft_key_movespeed(key, info);
	else if (key == KEY_K || key == KEY_L)
		ft_key_rotatespeed(key, info);
	// else if (key == KEY_Z || key == KEY_X || key == KEY_C || \
	// key == KEY_A || key == KEY_S || key == KEY_D)
	// 	ft_key_rotate(key, data);
	// else if (key == KEY_PLUS || key == KEY_MINUS)
	// 	ft_key_zoom(key, data);
	// else if (key == KEY_UP || key == KEY_DOWN || \
	// key == KEY_LEFT || key == KEY_RIGHT)
	// 	ft_key_offset(key, data);
	// else if (key == KEY_P || key == KEY_O)
	// 	ft_key_mode(key, data);
	// else if (key == KEY_ENTER || key == KEY_I)
	// 	ft_key_init(key, data);
	// else if (key == KEY_Q || key == KEY_W)
	// 	ft_key_altitude(key, data);
	return (1);
}
