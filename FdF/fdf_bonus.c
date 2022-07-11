/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:52:00 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/11 10:25:38 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_mms_20210621/mlx.h"
#include "fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2 || ft_check_filename(argv[1]) == FALSE)
	{
		write(2, "ERROR : argc != 2 || argv[1] != *.fdf\n", 38);
		return (1);
	}
	data = ft_init_data(argv[1]);
	ft_handle_map(data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &ft_key_press, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, &ft_close_win, data);
	mlx_loop(data->mlx);
	return (0);
}
