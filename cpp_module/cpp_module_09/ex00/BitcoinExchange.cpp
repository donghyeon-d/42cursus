#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(char *file) {
	std::fstream readfile(file);
	t_data data;
	if (readfile.is_open() == false) {
		return ;
	}
	else {
		string line;
		while (!readfile.eof())
		{
			std::getline(readfile, line);
			data = parse_line(line);
			_data.push_back(data);
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
	_data = ref._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {

}

t_data BitcoinExchange::parse_line(std::string &line) {
	t_date data;
	data.error = TRUE;

	if (line.length() < 14) {
		data.error = BADINPUT;
		return data;
	}
	int year(std::atoi(line.substr(0, 4)));
	int month(std::atoi(line.substr(5, 2)));
	int day(std::atoi(line.substr(8, 2)));

	data.date = line.substr(0, 10);
	data.value = line.substr(13);
	std::stringstream ssFloat(data.value);
	float value(0);
	ssFloat >> value;

	if ((line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | ")) {
		data.date = "Wrong Format";
		data.error = BADINPUT;
		return data;
	}
	for (int i = 13; i < line.length(); i++) {
		if (std::isdigit(line[i]) == flase){
			data.date = "Wrong Format";
			data.error = BADINPUT;
			return data;
		}
	}
	if (year < 2009 || 2023 < year) || \
		(month < 1 || month > 12) || \
		(day < 1 || day > 31) || \
		(month == 2 && day > 28) || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		data.error = BADINPUT;
		return data;
	}
	if (value > 999) {
		data.error = TOOLARGE;
		return data;
	}
	else if (value < 1) {
		data.error = NOTPOSITIVE;
		return data;
	}
}

void	BitcoinExchange::print_one_data(t_data data) {
	if (data.error == NOTPOSITIVE)
	switch (data.error) {
		case TRUE:
			std::cout << data.date << " => " << data.value \
			<< " = " << data.exchanged_value << std::endl;
			break ;
		case NOTPOSITIVE:
			std::cout << "Error: not a positive number." << std::endl;
			break ;
		case BADINPUT:
			std::cout << Error: bad input << " => " << data.date << std::endl;
			break ;
		case TOOLARGE:
			std::cout << "Error: too large a number." << std::endl;
			break ;
	}
}

bool	BitcoinExchange::exchange() {
	if (_data.empty() == true)
		return false;

	float value(0);
	for (std::deque<t_data>::iterator it = _data.begin(); it != _data.end(); it++) {
		std::stringstream ssFloat(data.value);
		ssFloat >> exchanged_value;
		// TODO : exchange 어떻게?
	}
	return true;
}

void BitcoinExchange::print_exchanging_result() {
	for (std::deque<t_data>::iterator it = _data.begin(); it != _data.end(); it++) {
		print_one_data(*it);
	}
}