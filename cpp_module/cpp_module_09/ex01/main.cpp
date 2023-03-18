#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error : argc != 2" << std::endl;
		return 0;
	}
	RPN rpn(argv[1]);
	try {
		std::cout << rpn.calc() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}