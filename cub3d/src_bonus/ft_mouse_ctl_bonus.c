/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_ctl_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:35:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:28:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d_bonus.h"

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
