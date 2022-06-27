#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "c.h"

void	exit_with_flag(int flag)
{
	if (flag == MAP_ERROR)
		write(1, "Map error\n", 10);
	exit(1);
}

// 일단 char **에 다 넣기
// 사이즈

t_pos	**make_map(char *map)
{
	char *temp;
	t_pos **new_map;
	
	fd = open(map);
	temp = gnl(fd);
	while (temp != NULL)
	{
		ft_split(temp, ' ');
		길이 확인 (윗 줄 길이랑 다르면 exit);
		t_pos *new_line 만들기(atoi, xyz설정)
		new_line을 list A에 담기
		gnl 횟수 확인 ( = y 확인);
	}
	new_map = malloc(sizeof(t_pos *) * ft_lstsize(A));
	한글자씩 
}