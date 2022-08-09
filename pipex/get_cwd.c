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

char    *get_name()
{
    int len;
    int i;
    int j;
    char *name;
    char *ret;

    name = getcwd(NULL, 0);
    len = ft_strlen(name);
    i = len - 1;
    while (name[i] !='/')
        i--;
    ret = malloc(sizeof(char) * (len - i));
    if (ret == NULL)
        // print_error_exit();
        exit(1);
    j = -1;
    while (++j < len - i - 1)
        ret[j] = name[i + 1 + j];
    ret[j] = '\0';
    free(name);
    return(ret);
}

int main()
{
    char *name;

    name = get_name();
    printf("%s\n", name);

}
