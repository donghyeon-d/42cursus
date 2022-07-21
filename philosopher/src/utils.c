#include "philosopher.h"

int ft_isdigit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

int	ft_atoi_positive(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
    if (str == NULL)
        return (-1);
	while (str[i] != '\0')
	{
        if (ft_isdigit(str[i]) == 0)
        {
            result = -1;
            break ;
        }
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}