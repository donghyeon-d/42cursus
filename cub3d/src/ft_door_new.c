/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:14 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/10/13 21:09:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_door_new(t_ray *ray, t_door *door)
{
	t_list	*list;

	list = ft_lstnew(door);
	if (list == NULL)
		error_exit("malloc fail");
	if (ray->door_lst == NULL)
	{
		ray->door_lst = list;
	}
	else
		ft_lstadd_front(&ray->door_lst, list);
}
