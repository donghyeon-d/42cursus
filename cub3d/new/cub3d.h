#ifndef CUB3D_H
# define CUB3D_H

// event 
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
//key
# define KEY_ESC	53
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_O		31
# define KEY_P		35
# define KEY_K		40
# define KEY_L		37

# define KEY_Z		6
# define KEY_X		7
# define KEY_C		8
# define KEY_Q		12
# define KEY_I		34
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_PLUS	24
# define KEY_MINUS	27
# define KEY_ENTER	36

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define WIN_WIDHT 640
#define WIN_HEIGHT 480
#define IMG_WID 640
#define IMG_HEI 480

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define	WEST 3

// int	worldMap[10][10] = 
// {
// 	{1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,1},
// 	{1,0,0,0,0,0,2,0,2,1},
// 	{1,3,3,3,0,0,2,2,2,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1}
// };

typedef struct	s_img
{
	void	*img;
	int		*ad;
	int		bpp;
	int		len;
	int		end;
	int		wid;
	int		hei;
} t_img;


typedef struct	s_ray
{
	double rayDirX; // 광선의 방향 벡터 X
	double rayDirY; // 광선의 방향 벡터 Y
	double raydir;
	double sideDistX; // 시작지점에서 Y절편 까지의 거리
	double sideDistY; // 시작지점에서 X절편 까지의 거리
	double deltaDistX; // X가 1 증가했을 때 거리
	double deltaDistY; // Y가 1 증가했을 때 거리
	int	stepX; // 1 or -1
	int stepY; // 1 or -1
	int mapX; // 광선이 닿은 벽 x좌표. 처음은 posX
	int mapY; // 광선이 닿은 벽 y좌표. 처음은 posY
	double wallDist; // 광선까지의 거리
	int wallside; // 광선이 벽의 어느면에 닿았는지. 0 = x, 1 = y
	double line_height; // 광선과의 거리를 통해 알게되어 출력할 높이
	int line_start; // line의 start 지점
	int line_end; // line의 end 지점
	int color;  // line의 color
}	t_ray;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double carmera_x;
	void	*mlx;
	void	*win;
	void	*img;
	int		*ad;
	int		bpp;
	int		len;
	int		end;
	double	moveSpeed;
	double	rotSpeed;
	int		**worldmap;
	int		floor_color;
	int		ceiling_color;
	int		map_wid;
	int		map_hei;
	// int		**texture;
	t_img	*texture;
	char	**file;
	t_ray	*ray;
}	t_info;



// 1 = 0xFF0000
// 2 = 0x00FF00
// 3 = 0x0000FF
// 4 = (12, 18)

// key.c
int	ft_key_press(int key, t_info *info);
int	ft_close_win(void);


// void	get_ray_diretion(t_info *info, t_ray *ray, int x);
// void	get_delta_dist(t_info *info, t_ray *ray, int x);
// void	get_side_dist(t_info *info, t_ray *ray, int x);
// void	get_wall_dist(t_info *info, t_ray *ray);
// void	calc_dist_to_wall(t_ray *ray);
// void	get_distance_to_wall(t_info *info, t_ray *ray, int x);
// void	get_wall_height(t_info *info, t_ray *ray, int x);
// void	get_color(t_info *info, t_ray *ray);
// void	draw_vertical(t_info *info, t_ray *ray, int x);


// init.c
t_info	*ft_create_info();
t_ray	*ft_create_ray(t_info *info);

//wall_dist.c
void	ft_get_distance_to_wall(t_info *info, t_ray *ray, int x);

//wall_height.c
void	ft_get_wall_height(t_info *info, t_ray *ray, int x);

//color.c
int		ft_get_color(t_info *info, t_img *img, int x, int y);

// draw.c
void	ft_draw_vertical(t_info *info, t_ray *ray, int x);

// main.c
void	screen_all(t_info *info, t_ray *ray);

// texture.c
void	ft_img_copy_to_texture(t_info *info, t_img *img, char *file);
void	ft_load_texture(t_info *info);

#endif