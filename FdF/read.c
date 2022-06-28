#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "c.h"
#include "./get_next_line/get_next_line.h"

int main(int argc, char *argv[])
{
	char	*get;
	int		fd;

	fd = open(argv[1], O_RDWR);
	get = get_next_line(fd);
	printf("%s\n", get);
}