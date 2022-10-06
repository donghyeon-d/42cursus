#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "cub3d.h"

static t_info	*init_info(void)
{
	t_info	*info;

	info = ft_malloc(sizeof(t_info));
	info->pos_x = 0; // player 위치 x
	info->pos_y = 0; // player 위치 y
	info->worldmap = NULL; // 파싱한 map의 2차원 배열 형태
	info->map_wid = 0; // 맵의 가로 크기 (가장 큰 부분 기준)
	info->map_hei = 1; // 맵의 세로 크기 (맵 줄 수)
	info->floor_color = 0; // 바닥 색
	info->ceiling_color = 0; // 천장 색
	// info->mlx = mlx_init();
	// info->win = mlx_new_window(info->mlx, WIN_WID, WIN_HEI, "cub3D");
	info->move_speed = MOVE_SPEED;
	info->rot_speed = ROT_SPEED;
	info->texture_file_name[0] = NULL;
	info->texture_file_name[1] = NULL;
	info->texture_file_name[2] = NULL;
	info->texture_file_name[3] = NULL;
	return (info);
}
#include <stdio.h>
int main(int argc, char *argv[])
{
	t_info	*info;

	if (argc != 2)
		error_exit("Wrong argc");
	info = init_info();
	parse(argv[1], info);
	for (int i = 0; i < info->map_hei; i++)
	{
		for (int j = 0; j < info->map_wid; j++)
		{
			printf("%c", info->worldmap[i][j]);
		}
		printf("\n");
	}
	system("leaks a.out");
}