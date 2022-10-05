#include <string.h>
#include <stdlib.h>
#include "../minilibx_mms_20210621/mlx.h"
#include "cub3d.h"

t_info	*ft_create_info()
{
	t_info	*new;

	new = malloc(sizeof(t_info));
	if (new == NULL)
		exit(1);
	new->texture = malloc(sizeof(char *) * 4);
	if (new->texture == NULL)
		exit(1);
	new->posX = 0;
	new->posY = 0;
	new->dirX = 0;
	new->dirY = 0;
	new->planeX = 0;
	new->planeY = 0;
	new->carmera_x = 0;
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, IMG_WID, IMG_HEI, "cub3d");
	new->img = mlx_new_image(new->mlx, IMG_WID, IMG_HEI);
	new->ad = (int *)mlx_get_data_addr(new->img, &new->bpp, &new->len, &new->end);
	new->moveSpeed = 0.05;
	new->rotSpeed = 0.05;
	new->floor_color = 0x000000;
	new->ceiling_color = 0xFFFFFF;
	return (new);
}

t_ray	*ft_create_ray(t_info *info)
{
	t_ray	*new;

	new = malloc(sizeof(t_ray));
	if (new == NULL)
		exit(1);
	bzero(new, sizeof(t_ray));
	new->mapX = (int)(info->posX);
	new->mapY = (int)(info->posY);
	return (new);
}
