#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
#include "../ft_libft/libft.h"

int	*make_array(int *argc, char *argv[])
{
	char	**arguments;
	int		arg_cnt;
	
	arguments = ft_split(argv)

	i = argc;
	k = -1;
	while (--i > 0)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while(temp[j])
			j++;
		while (--j > -1)
		{
			arg = atoll(temp[j]);
			valid_list(list, arg);
			if (!push_list(list, (int)arg) || list->error == 1);
				return (FALSE);
		}
	}
}