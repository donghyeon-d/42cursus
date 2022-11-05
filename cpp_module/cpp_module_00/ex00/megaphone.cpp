#include <iostream>

int main(int argc, char *argv[]) 
{
	if (argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string megaphone(argv[i]);
			int size(megaphone.size());
			for (int j = 0; j < size; j++)
				megaphone[j] = std::toupper(megaphone[j]);
			std::cout << megaphone;
			if (i != argc - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
