/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:11:09 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

static void	init_screen_img(void *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx, WIN_WID, WIN_HEI);
	img->addr = \
		(int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
}

static void	texture_file_to_image(void *mlx, t_img *img, char *file)
{
	file[ft_strlen(file) - 1] = '\0';
	img->img = mlx_xpm_file_to_image(mlx, file, &img->wid, &img->hei);
	if (img->img == NULL)
		error_exit("Can't find texture file or No xpm file");
	img->addr = \
		(int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
}

static void	door_file_to_image(void *mlx, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(mlx, file, &img->wid, &img->hei);
	img->addr = \
		(int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
}

void	init_images(t_info *info)
{
	int		i;

	init_screen_img(info->mlx, &info->screen_img);
	i = -1;
	while (++i < 4)
		texture_file_to_image(info->mlx, &info->texture[i], \
		info->texture_file[i]);
	door_file_to_image(info->mlx, &info->texture[D_CLOSE], DOOR1);
	door_file_to_image(info->mlx, &info->texture[D_MOVEMENT1], DOOR2);
	door_file_to_image(info->mlx, &info->texture[D_MOVEMENT2], DOOR3);
	door_file_to_image(info->mlx, &info->texture[D_MOVEMENT3], DOOR4);
	door_file_to_image(info->mlx, &info->texture[D_MOVEMENT4], DOOR5);
	door_file_to_image(info->mlx, &info->texture[D_MOVEMENT5], DOOR6);
	door_file_to_image(info->mlx, &info->texture[D_OPEN], DOOR7);
}
