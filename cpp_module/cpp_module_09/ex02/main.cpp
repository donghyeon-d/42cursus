#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: input more argv" << std::endl;
		return 0;
	}
	try {
		PmergeMe pmergeme;
		if (pmergeme.setNumbers(argv) == false)
			return 0;
		pmergeme.insertSortVec();
		pmergeme.insertSortDeq();
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return 0;
}