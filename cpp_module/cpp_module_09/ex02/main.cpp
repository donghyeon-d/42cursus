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
		std::cout << "before : "; pmergeme.printNum();

		clock_t start(0), finish(0);
		// vector
		start = std::clock();
		pmergeme.sortVec(pmergeme.getVec(), 0, pmergeme.getVec().size() - 1);
		finish = std::clock();
		std::cout << "vec time : " << finish - start << "ms => ";
		pmergeme.printVec();

		// deque
		start = std::clock();
		pmergeme.sortDeq(pmergeme.getDeq(), 0, pmergeme.getDeq().size() - 1);
		finish = std::clock();
		std::cout.precision(6);
		std::cout << "Deq time : " << finish - start << "ms => ";
		pmergeme.printDeq();

		// set
		start = std::clock();
		pmergeme.sortSet();
		finish = std::clock();
		std::cout.precision(6);
		std::cout << "Set time : " << finish - start << "ms => ";
		pmergeme.printSet();

	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return 0;
}