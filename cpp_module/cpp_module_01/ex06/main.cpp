#include "HarlFilter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "You must put one complain" << std::endl;
		return 0;
	}
	std::string level(argv[1]);
	HarlFilter harlFilter;
	harlFilter.complain(level);
	return 0;
}