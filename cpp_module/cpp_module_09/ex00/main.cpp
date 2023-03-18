#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::cout;
		return 0;
	}
	try {
		BitcoinExchange bitcoin_exchange;
		bitcoin_exchange.exchangingPrint(argv[1]);
	}
	catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}