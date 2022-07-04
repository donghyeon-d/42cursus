/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:51:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/04 21:47:20 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "./ft_libft/libft.h"
# include "./get_next_line/get_next_line.h"

// WIDTH & HEITH
# define WIN_HEI 1000
# define WIN_WID 1200
# define IMG_HEI 1000
# define IMG_WID 1200

// error flag
# define MAP_ERROR 1
# define TRUE 1
# define FALSE 0

// event 
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17

//key
# define KEY_ESC 53//exit
# define KEY_Z 6//rotate x
# define KEY_X 7//rotate y
# define KEY_C 8//rotate z
# define KEY_A 0//rotate x_reverse
# define KEY_S 1//rotate y_reverse
# define KEY_D 2//rotate z_reverse
# define KEY_Q 12//altitude +
# define KEY_W 13//altitude -
# define KEY_I 34//
# define KEY_O 31//
# define KEY_UP 126//offset up
# define KEY_DOWN 125//offset down
# define KEY_LEFT 123//offset left
# define KEY_RIGHT 124//offset right
# define KEY_PLUS 24//zoom in
# define KEY_MINUS 27//zoom out
# define KEY_ENTER 36//init

//color
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

//distance 점간 거리 - 확대시 키워줌
//angle_radian 시계방향으로 돌려줄 각도

typedef struct s_pos {
	double	x;
	double	y;
	double	z;
	int		color;
}	t_pos;

typedef struct s_map {
	t_pos	**table;
	t_list	*read_list;
	int		height;
	int		width;
	double	offset_x;
	double	offset_y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_map;

typedef struct s_env {
	double	alpha;
	double	beta;
	double	gamma;
	double	alt;
	double	zoom;
}	t_env;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	int		*ad;
	char	*map_file;
	t_map	*map;
	t_env	*env;
	int		bpp;
	int		len;
	int		end;
}				t_data;

// void	ft_draw_line(t_data *img, t_pos from, t_pos to, int color);
void	ft_draw_line_all(t_data *img, t_map *map, int color);

t_map	*make_map(char *map_file);

int		key_press(int keycode, t_data *img);
int		ft_close_win(void *param);

void	ft_draw_background(t_data *data);
int		ft_handle_map(t_data *data);

// init.c
t_env	*ft_init_env(void);
t_data	*ft_init_data(char *map_file);
t_map	*ft_init_map(int height);

// map
void	ft_adj_map(t_data *data);
void	ft_adj_map_altitude(t_data *data);
void	ft_adj_map_offset(t_data *data);
void	ft_adj_map_rotate(t_map *map, t_env *env);
void	ft_adj_map_zoom(t_data *data);


void	ft_make_map_table(t_map	*map, t_list *read_list);
void	ft_free_double(char **temp);
void display_map(t_map *map);

#endif