#include <math.h>
#include <stdlib.h>
#include "cub3d.h"

int	ft_close_win(void)
{
	exit(0);
	return (0);
}

void	ft_key_move(int key, t_info *info)
{
	if (key == KEY_W && info->posY < info->map_hei - 1)
		info->posY += info->moveSpeed;
	else if (key == KEY_S && info->posY > 1)
		info->posY -= info->moveSpeed;
	else if (key == KEY_A && info->posX < info->map_wid - 1)
		info->posX -= info->moveSpeed;
	else if (key == KEY_D && info->posX > 1)
		info->posX += info->moveSpeed;
	screen_all(info, info->ray);
}

void	ft_key_rotate(int key, t_info *info)
{
	int	x;
	int	y;
	int plane_x;
	int plane_y;

	x = info->dirX;
	y = info->dirY;
	plane_x = info->planeX;
	plane_y = info->planeY;
	if (key == KEY_LEFT)
	{
		info->dirX = x * cos(info->rotSpeed) - y * sin(info->rotSpeed);
		info->dirY = x * sin(info->rotSpeed) + y * cos(info->rotSpeed);
		info->planeX = plane_x * cos(info->rotSpeed) - plane_y * sin(info->rotSpeed);
		info->planeY = plane_x * sin(info->rotSpeed) + plane_y * cos(info->rotSpeed);
	}
	else if (key == KEY_RIGHT)
	{
		info->dirX = x * cos(info->rotSpeed) + y * sin(info->rotSpeed);
		info->dirY = y * cos(info->rotSpeed) - x * sin(info->rotSpeed);
		info->planeX = plane_x * cos(info->rotSpeed) + plane_y * sin(info->rotSpeed);
		info->planeY = plane_y * cos(info->rotSpeed) - plane_x * sin(info->rotSpeed);
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