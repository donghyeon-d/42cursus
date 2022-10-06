/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:33:08 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 17:02:59 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "cub3d.h"
#include "libft.h"

void	error_exit(char *message)
{
	write(2, "Error : ", 8);
	ft_putendl_fd(message, 2);
	exit(1);
}