/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_ctl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:35:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 13:50:10 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	ft_mouse_ctl(int button, int x, int y, t_info *info)
{
	if (button == M_CLK_L)
	{
		mlx_mouse_show();
		info->mouse_ctl = FALSE;
	}
	else if (button == M_CLK_R)
	{
		mlx_mouse_hide();
		info->mouse_ctl = TRUE;
	}
	x += y;
	return (0);
}
