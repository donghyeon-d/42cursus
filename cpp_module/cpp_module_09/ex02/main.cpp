#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: input more argv" << std::endl;
		return 0;
	}
	try {
		// PmergeMe pmergeme(argv);
		PmergeMe pmergeme;
		pmergeme.setNumbers(argv);
		pmergeme.timeCheckList();
		pmergeme.timeCheckSet();
		pmergeme.timeCheckVector();
		pmergeme.printDiff();
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return 0;
}