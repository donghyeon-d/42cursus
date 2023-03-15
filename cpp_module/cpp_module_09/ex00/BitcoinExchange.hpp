#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <except>

#define TRUE 1
#define NOTPOSITIVE -1
#define BADINPUT -2
#define TOOLARGE -3
#define CSVFILE "./data.csv"

typedef struct s_data {
	std::string date;
	std::string value;
	float exchanged_value;
	int error;
} t_data;

class BitcoinExchange {
	private:
		std::deque<t_data> _data;
		std::map<std::string, float> _rate;
		bool valid_check_data_line(std::string &line);
		t_data parse_input_line(std::string &line);
		void	print_one_data(t_data data);
		void getCSV();
		class InvalidFileException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		BitcoinExchange();
		BitcoinExchange(char *file);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();
		bool exchange();
		// bool is
		void print_exchanging_result();
};

float ft_stof(std::string str);

#endif
