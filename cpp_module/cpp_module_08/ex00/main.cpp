#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(i);

	std::vector<int>::iterator itr;
	itr = easyfind(arr, 1);
	if (itr == arr.end())
		std::cout << "false" << std::endl;
	else
		std::cout << "true : " << *itr << std::endl;

	itr = easyfind(arr, 120);
	if (itr == arr.end())
		std::cout << "false" << std::endl;
	else
		std::cout << "true : " << *itr << std::endl;
}
