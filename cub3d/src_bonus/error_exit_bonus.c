/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:33:08 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:40:00 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "cub3d_bonus.h"

void	error_exit(char *message)
{
	write(2, "Error : ", 8);
	ft_putendl_fd(message, 2);
	exit(1);
}
