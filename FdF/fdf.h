/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:51:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/30 11:32:28 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./ft_libft/libft.h"
# include "./get_next_line/get_next_line.h"
# define WIN_HEI 1000
# define WIN_WID 1200
# define IMG_HEI 1000
# define IMG_WID 1200
// error flag
# define MAP_ERROR 1
# define TRUE 1
# define FALSE 0

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC 53
# define KEY_Z 6
# define KEY_X 7

//distance 점간 거리 - 확대시 키워줌
//angle_radian 시계방향으로 돌려줄 각도

typedef struct s_pos {
	double	x;
	double	y;
	double	z;
}	t_pos;

typedef struct s_map {
	int		height;
	int		width;
	int		distance;
	t_pos	**table;
}	t_map;

typedef struct s_env {
	double	angle_radian;
	double	alpha;
	int		distance;
	int		altitude;
	int		x_min;
	int		y_min;
}	t_env;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	int		*ad;
	int		bpp;
	int		len;
	int		end;
	t_map	*map;
	t_env	*env;
}				t_data;

void	ft_draw_line(t_data *img, t_pos from, t_pos to);
void	ft_draw_line_all(t_map *map, t_data *img);

void	display_map(t_map *map);

int		ft_map_valid_check(t_map *map, t_list *read_list);
t_map	*ft_init_map(int height);
void	ft_make_map_table(t_map	*map, t_list *read_list);
t_map	*make_map(char *map_file);

int		key_press(int keycode, t_data *img);
int		ft_close_win(void *param);

void	ft_rotate_matrix_clockwise(t_pos *dot, t_env *env);
void	ft_add_altitude(t_pos *dot, t_env *env);
void	ft_rotate_map(t_map *map, t_env *env);

#endif