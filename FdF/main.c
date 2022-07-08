#include <stdio.h>
#include <mlx.h>
#include "./get_next_line/get_next_line.h"
#include "./ft_libft/libft.h"
// #include "fdf_bonus.h"

#define IMG_WID 1920
#define IMG_HEI 1080

// void display_map(t_map *map)
// {
// 	for (int i = 0; i < map->height; i++)
// 	{
// 		for (int j = 0; j < map->width; j++)
// 			printf("{%.2f %.2f %.2f} ", map->map_table[i][j].x, map->map_table[i][j].y, map->map_table[i][j].z);
// 		printf("\n");
// 	}
// 		printf("\n");
// 			printf("\n");
// }

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}


int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = -1;
	sign = 1;
	result = 0;
	if ('+' == *str || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (!ft_isdigit(*str))
			exit(1);
	}	
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			break ;
		if (str[i] != '\n')
			result = result * 10 + (str[i] - '0');
	}
	if ((str[i] != '\0' && !ft_isdigit(str[i])))
		exit(1);
	return ((int)(sign * result));
}


int main(int argc, char *argv[])
{
	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, IMG_WID, IMG_HEI, "FdF");
	// void *img = mlx_new_image(mlx, IMG_WID, IMG_HEI);
	// mlx_string_put(mlx, win, 0, 0, 0xFFFFFFF, "hello!");
	// mlx_loop(mlx);
	printf("%d\n", ft_atoi(argv[1]));
}