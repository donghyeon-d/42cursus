#include "MyFile.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "argc != 4" << std::endl;
		return (0);
	}

	std::string fileName(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	MyFile myFile(fileName);
	myFile.replace(s1, s2);
}