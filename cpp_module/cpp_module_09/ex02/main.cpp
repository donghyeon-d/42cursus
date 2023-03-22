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
		pmergeme.sortVec(pmergeme.getVec(), 0, pmergeme.getVec().size() - 1);
		std::cout << "vec : "; pmergeme.printVec();
		pmergeme.insertSortDeq(pmergeme.getDeq());
		std::cout << "deq : "; pmergeme.printDeq();
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return 0;
}