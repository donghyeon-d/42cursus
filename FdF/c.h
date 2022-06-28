#ifndef FDF_H
# define FDF_H

#include "./ft_libft/libft.h"
#include "./get_next_line/get_next_line.h"
#define	WIN_HEIGHT 1000
#define WIN_WIDTH 1000
#define IMG_HEIGHT 600
#define IMG_WIDTH 800
// error flag
#define	MAP_ERROR 1
#define TRUE 1
#define FALSE 0


typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_pos {
	int	x;
	int	y;
	int	z;
}	t_pos;

typedef struct s_map {
	int	height;
	int	width;
	t_pos **map_table;
}	t_map;


void	ft_draw_line(t_data *img, t_pos from, t_pos to, int distance);


void display_map(t_map *map);

int		ft_map_valid_check(t_map *map, t_list *read_list);
t_map	*ft_init_map(int height);
void	ft_make_map_table(t_map	*map, t_list *read_list);
t_map	*make_map(char *map_file);

#endif