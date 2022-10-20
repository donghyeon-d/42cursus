#include <string.h>
#include <iostream>

void	ft_to_large(char *str)
{
	int i;

	i = -1;
	while (++i < (int)strlen(str))
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