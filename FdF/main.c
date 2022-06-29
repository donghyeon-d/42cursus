#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include "./ft_libft/libft.h"
#include "c.h"

void display_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("{%d %d %d} ", map->map_table[i][j].x, map->map_table[i][j].y, map->map_table[i][j].z);
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	t_map *map;
	if (argc != 2)
	{
		write(2, "put map file\n", 13);
		return (0);
	}
	map = make_map(argv[1]);
	// map->height = 2;
	// map->width = 2;
	display_map(map);
	// printf("%d", ft_atoi("-123\n"));
	// system("leaks a.out");
}