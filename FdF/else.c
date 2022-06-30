
void display_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
			printf("{%.2f %.2f %.2f} ", map->table[i][j].x, map->table[i][j].y, map->table[i][j].z);
		printf("\n");
	}
}

void	ft_add_distance(t_map *map, int distance)
{
	int	i;
	int	j;

	i = -1;
	while (i < map->height)
	{
		while (j < map->width)
		{
			map->table[i][j].x *= distance;
			map->table[i][j].y *= distance;
			map->table[i][j].z *= distance;
		}
	}
}