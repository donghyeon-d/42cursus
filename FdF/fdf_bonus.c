/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/08 14:58:26 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		write(1, "argument!!\n", 11);
		return (0);
	}
	data = ft_init_data(argv[1]);
	ft_handle_map(data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, &ft_close_win, data);
	mlx_loop(data->mlx);
}
