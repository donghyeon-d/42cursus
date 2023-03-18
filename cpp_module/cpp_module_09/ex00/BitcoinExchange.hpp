#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <map>

#define TRUE 1
#define NOTPOSITIVE -1
#define BADINPUT -2
#define TOOLARGE -3
#define CSVFILE "./data.csv"

typedef struct s_data {
	std::string date;
	float value;
	float exchanged_value;
	int error;
} t_data;

class BitcoinExchange {
	private:
		std::map<std::string, float> _rate;
		bool validCheckDataLine(std::string &line);
		t_data parseInputLine(std::string &line);
		void	printOneData(t_data &data);
		void getCSV();
		class InvalidFileException : public std::exception
        {
            public :
                const char *what() const throw();
        };
		void exchange(t_data &data);
		float findRateValue(std::string &key);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();
		void exchangingPrint(char *file);
};

float ftStof(std::string str);
bool isLeapYear(int year);

#endif
