#include <string.h>
#include <iostream>

void	ft_to_large(char *str)
{
	int i;
	int	len;

	i = -1;
	len = (int)strlen(str);
	while (++i < len)
		str[i] = toupper(str[i]);
}

int main(int argc, char *argv[]) 
{
	if (argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			ft_to_large(argv[i]);
			std::cout << argv[i] << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
