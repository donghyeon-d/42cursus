/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:10:20 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/06 20:21:09 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	parse(char *file, t_info *info)
{
	// 파일 유효성 검사
	file_check(file);
	get_map_info(file, info);
	// get_map_info
		// get_texture
		// get_color
	// get_map

}
