#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "c.h"

int		ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	from_file_to_file(int from_fd, int to_fd) // gnl로 받아야되나
{
	int		n;
	char	*str;

	str = get_next_line(from_fd); // gnl 안에서 errno(exit) 설정 필요
	n = ft_strlen(str);
	while (str != NULL)
	{
		if (write(to_fd, str, n) < 0)
            exit(1);
			// print_error_exit();
		free(str);
		str = get_next_line(from_fd);
		n = ft_strlen(str);
	}
}

int main()
{
    int fd = open("./ppp", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
    from_file_to_file(0, fd);
    close(fd);
    // char *str = get_next_line(0);
    // int len = strlen(str);
    // while (str != NULL)
    // {
    //     len = strlen(str);
    //     write(fd, str, len);
    //     free(str);
    //     str = get_next_line(0);
    // }
}
