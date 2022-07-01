/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:46:28 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/01 15:04:16 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf_bonus.h"

t_env	*ft_init_env(void)
{
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		exit(1);
	new_env->alpha = -0.7;
	new_env->beta = -0.7;
	new_env->gamma = -0.7;
	new_env->alt = 3;
	new_env->zoom = 50;
	return (new_env);
}

t_data	*ft_init_data(char *map_file)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		exit(1);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, IMG_WID, IMG_HEI, "FdF");
	d->img = mlx_new_image(d->mlx, IMG_WID, IMG_HEI);
	d->ad = (int *)mlx_get_data_addr(d->img, &d->bpp, &d->len, &d->end);
	d->map_file = map_file;
	if (d->mlx == NULL || d->win == NULL || d->img == NULL || d->ad == NULL)
		exit(1);
	d->map = make_map(map_file);
	d->env = ft_init_env();
	return (d);
}