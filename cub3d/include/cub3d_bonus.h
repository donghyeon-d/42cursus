/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:27:16 by dongchoi          #+#    #+#             */
/*   Updated: 2022/10/14 14:35:46 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"

# define WIN_WID 1280
# define WIN_HEI 720
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1
# define TRUE 1
# define FALSE 0

# define EAST_OR_WEST 0
# define NORTH_OR_SOUTH 1

# define DOOR1 "./pics/door1.xpm"
# define DOOR2 "./pics/door2.xpm"
# define DOOR3 "./pics/door3.xpm"
# define DOOR4 "./pics/door4.xpm"
# define DOOR5 "./pics/door5.xpm"
# define DOOR6 "./pics/door6.xpm"
# define DOOR7 "./pics/door7.xpm"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13

# define K_O 31
# define K_P 35

# define K_AR_L 123
# define K_AR_R 124

# define K_SP 49
# define K_ESC 53
# define K_TAB 48

# define M_CLK_L 1
# define M_CLK_R 2

# define C_MAP_PLAYER 0xFF0000
# define C_MAP_PATH 0xFFFFFF
# define C_MAP_DOOR 0x0000FF
# define C_MAP_WALL 0x000000
# define C_EMPTY -16777216

enum e_map_file_info
{
	MAP_TEXTURE = 1,
	MAP_COLOR,
	MAP_MAP
};

enum e_cardinal_directions
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum e_door_status
{
	D_CLOSE = 4,
	D_MOVEMENT1,
	D_MOVEMENT2,
	D_MOVEMENT3,
	D_MOVEMENT4,
	D_MOVEMENT5,
	D_OPEN
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		len;
	int		end;
	int		wid;
	int		hei;
}	t_img;

typedef struct s_draw
{
	t_img	texture;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_draw;

typedef struct s_door
{
	int		map_x;
	int		map_y;
	double	wall_dist;
	int		wall_side;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	t_img	texture;
	int		tex_x;
	double	tex_start;
	double	step;
}	t_door;

typedef struct s_ray
{
	double	carmera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	double	wall_dist;
	int		wall_side;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	t_list	*door_lst;
}	t_ray;

typedef struct s_info
{
	char	start_dir;
	int		mouse_ctl;
	int		minimap_on;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	t_img	screen_img;
	double	move_speed;
	double	rot_speed;
	int		**worldmap;
	int		map_wid;
	int		map_hei;
	int		floor_color;
	int		ceiling_color;
	char	*texture_file[4];
	t_img	texture[11];
	t_img	minimap;
	t_ray	ray;
}	t_info;

void	*ft_malloc(size_t size);
void	error_exit(char *message);
int		file_check_type(char *filename);
void	file_check(char *filename);
int		what_info(char *file);
void	pass_newline(int fd, char **line);
void	get_map_texture(int fd, char **line, t_info *info);
void	get_map_color(int fd, char **line, t_info *info);
void	get_map_info(char *file, t_info *info);
void	get_map(int fd, char **line, t_info *info);
void	map_valid_check(int **map, int hei, int wid);
void	parse(char *file, t_info *info);
char	*get_next_line(int fd);
void	get_player(t_info *info);
void	init_images(t_info *info);
int		ft_raycasting(t_info *info);
void	init_ray(t_info *info, t_ray *ray, int x);
void	start_dda(t_info *info, t_ray *ray);
void	take_wall_point(t_info *info, t_ray *ray);
void	draw_line(t_info *info, t_ray *ray, int x);
t_img	get_draw_texture(t_info *info, t_ray *ray);
int		get_texture_point_x(t_info *info, t_ray *ray, t_img texture);
void	create_door(t_info *info, t_ray *ray);
void	ft_door_new(t_ray *ray, t_door *door);
int		ft_close_win(void);
int		ft_key_press(int key, t_info *info);
void	ft_key_move(int key, t_info *info);
int		ft_mouse_ctl(int button, int x, int y, t_info *info);
void	ft_rotate_clock(t_info *info, double angle);
int		ft_mouse_loop(t_info *info);
void	ft_minimap(t_info *info);
void	ft_door_control(t_info *info);
void	ft_key_rotate(int key, t_info *info);

#endif