#define	WIN_HEIGHT 1000
#define WIN_WIDTH 1000
#define IMG_HEIGHT 600
#define IMG_WIDTH 800
// error flag
#define	MAP_ERROR 1

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

void	ft_draw_line(t_data *img, t_pos from, t_pos to, int distance);

t_pos	**make_map(char *map);