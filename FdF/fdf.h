/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:51:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/07/11 10:06:38 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./ft_libft/libft.h"
# include "./get_next_line/get_next_line.h"

// WIDTH & HEITH
# define WIN_HEI 1080
# define WIN_WID 1920
# define IMG_HEI 1080
# define IMG_WID 1920
// error flag
# define TRUE	1
# define FALSE	0
// event 
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
//key
# define KEY_ESC	53
# define KEY_Z		6
# define KEY_X		7
# define KEY_C		8
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_Q		12
# define KEY_W		13
# define KEY_I		34
# define KEY_O		31
# define KEY_P		35
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_PLUS	24
# define KEY_MINUS	27
# define KEY_ENTER	36
//color
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define BLUE	0x0000FF
# define BLACK	0x000000
//key
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE 	3
# define X_EVENT_KEY_EXIT 		17

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
	double	mid_x;
	double	mid_y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_min;
	double	z_max;
}	t_map;

typedef struct s_env {
	double	alpha;
	double	beta;
	double	gamma;
	double	alt;
	double	zoom;
	int		init;
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

// map_parse
t_map	*ft_make_map(char *map_file);
void	ft_make_map_table(t_map	*map, t_list *read_list);
int		ft_check_filename(char *filename);
//find_min_max
void	ft_find_xy_max_min(t_map *map);
void	ft_find_z_max_min(t_map *map);
// clor
int		ft_find_pixel_color(t_pos from, t_pos to, int i, int step);
int		ft_color_vertical(t_pos from, t_pos to, int i, int step);
void	ft_color_setting(t_map *map);
// key
int		ft_key_press(int key, t_data *data);
void	ft_key_init(int key, t_data *data);
void	ft_key_mode(int key, t_data *data);
int		ft_close_win(void);
void	ft_key_altitude(int key, t_data *data);
void	ft_key_offset(int key, t_data *data);
void	ft_key_rotate(int key, t_data *data);
void	ft_key_zoom(int key, t_data *data);
// string.c
void	ft_string_put(t_data *data);
// draw.c
void	ft_draw_line_all(t_data *img, t_map *map);
// init.c
t_env	*ft_init_env(void);
t_data	*ft_init_data(char *map_file);
// map_adjust.c 
void	ft_handle_map(t_data *data);
void	ft_adj_map(t_data *data);
void	ft_double_to_int(t_map *map);
void	ft_draw_background(t_data *data);
// map adjust
void	ft_adj_map_altitude(t_data *data);
void	ft_adj_map_offset(t_data *data);
void	ft_adj_map_rotate(t_map *map, t_env *env);
void	ft_adj_map_zoom(t_data *data);
void	ft_adj_dot_xy(t_map *map, double x, double y);

#endif