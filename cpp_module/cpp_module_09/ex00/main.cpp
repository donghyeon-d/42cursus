#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Error: could not open file." << std::cout;
		return 0;
	}
	BitcoinExchange bitcoin_exchange(argv[1]);
	if (bitcoin_exchange.exchange() == false){
		std::cout << "Error : could not open file" << std::endl;
	}
	else {
		bitcoin_exchange.print_exchanging_result();
	}
	return 0;
}