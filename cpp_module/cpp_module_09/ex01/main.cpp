#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return 0;
	}
	RPN rpn(argv[1]);
	if (rpn.validCheck() == false) {
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << rpn.calc() << std::endl;
	}
	return 0;
}