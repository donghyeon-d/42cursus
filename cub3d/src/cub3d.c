/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:03:47 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/17 11:57:39 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

static t_info	*init_info(void)
{
	t_info	*info;

	info = ft_malloc(sizeof(t_info));
	info->pos_x = 0;
	info->pos_y = 0;
	info->worldmap = NULL;
	info->map_wid = 0;
	info->map_hei = 1;
	info->floor_color = -1;
	info->ceiling_color = -1;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIN_WID, WIN_HEI, "cub3D");
	info->move_speed = MOVE_SPEED;
	info->rot_speed = ROT_SPEED;
	mlx_mouse_hide();
	info->mouse_ctl = TRUE;
	info->minimap_on = FALSE;
	info->texture_file[0] = NULL;
	info->texture_file[1] = NULL;
	info->texture_file[2] = NULL;
	info->texture_file[3] = NULL;
	return (info);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc != 2)
		error_exit("Wrong argc");
	info = init_info();
	parse(argv[1], info);
	init_images(info);
	ft_raycasting(info);
	mlx_mouse_hook(info->win, ft_mouse_ctl, info);
	mlx_loop_hook(info->mlx, ft_mouse_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &ft_close_win, info);
	mlx_loop(info->mlx);
}
