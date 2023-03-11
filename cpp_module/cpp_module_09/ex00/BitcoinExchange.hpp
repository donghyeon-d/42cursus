#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

#define TRUE 1
#define NOTPOSITIVE -1
#define BADINPUT -2
#define TOOLARGE -3

typedef struct s_data {
	std::string date;
	std::string value;
	float exchanged_value;
	int err;
} t_data;

class BitcoinExchange {
	private:
		std::deque<t_data> _data;
		t_data parse_line(std::string &line);
		void	print_one_data(t_data data);
	public:
		BitcoinExchange();
		BitcoinExchange(char *file);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();
		bool exchange();
		bool is
		void print_exchanging_result();
};

#endif
