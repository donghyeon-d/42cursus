#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(char *file) {
	std::fstream readfile(file);
	t_data data;

	if (readfile.is_open() == false) {
		throw InvalidFileException();
	}
	else {
		std::string line;
		int line_num(1);
		while (!readfile.eof())
		{
			std::getline(readfile, line);
			if (line_num == 1) {
				if (line != "date | value") {
					data.error = BADINPUT;
				}
			}
			else
				data = parse_input_line(line);
			_data.push_back(data);
			line_num++;
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

void BitcoinExchange::getCSV() {
	std::fstream readfile(CSVFILE);

	if (readfile.is_open() == false) {
		throw InvalidFileException();
	}
	else {
		std::string line;
		int line_num(1);
		while (!readfile.eof())
		{
			std::getline(readfile, line);
			if (line_num == 1) {
				if (line != "date,exchange_rate") {
					throw InvalidFileException();
				}
			}
			else {
				if (!valid_check_data_line(line)) {
					throw InvalidFileException();
				}
				else {
					_rate[line.substr(0, 10)] = ft_stof(line.substr(11));
				}
			}
			line_num++;
		}
	}
}

const char *BitcoinExchange::InvalidFileException::what() const throw() {
	return ("Error: Invalid File");
}

bool BitcoinExchange::valid_check_data_line(std::string &line) {
	if (line.length() < 12) {
		return false;
	}

	if (line[4] != '-' || line[7] != '-' || line[10] != ',') {
		return false;
	}

	bool used_dot(false);
	for (unsigned int i = 11; i < line.length(); i++) {
		if (used_dot == true && line[i] == '.')
			return false;
		if (!std::isdigit(line[i]) && line[i] != '.')
			return false;
		if (line[i] != '.')
			used_dot = true;
	}

	int year(std::atoi(line.substr(0, 4).c_str()));
	int month(std::atoi(line.substr(5, 2).c_str()));
	int day(std::atoi(line.substr(8, 2).c_str()));
	if ((year < 2009 || 2023 < year) || \
		(month < 1 || month > 12) || \
		(day < 1 || day > 31) || \
		(month == 2 && day > 28) || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		return false;
	}
	return true;
}

float ft_stof(std::string str) {
	std::stringstream ssFloat(str);
	float value(0);
	ssFloat >> value;
	return value;
}

t_data BitcoinExchange::parse_input_line(std::string &line) {
	t_data data;
	data.error = TRUE;

	if (line.length() < 14) {
		data.error = BADINPUT;
		return data;
	}
	int year(std::atoi(line.substr(0, 4).c_str()));
	int month(std::atoi(line.substr(5, 2).c_str()));
	int day(std::atoi(line.substr(8, 2).c_str()));

	data.date = line.substr(0, 10);
	data.value = line.substr(13);

	if ((line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | ")) {
		data.date = "Wrong Format";
		data.error = BADINPUT;
		return data;
	}
	for (unsigned int i = 13; i < line.length(); i++) {
		if (std::isdigit(line[i]) == false){
			data.date = "Wrong Format";
			data.error = BADINPUT;
			return data;
		}
	}
	if ((year < 2009 || 2023 < year) || \
		(month < 1 || month > 12) || \
		(day < 1 || day > 31) || \
		(month == 2 && day > 28) || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		data.error = BADINPUT;
		return data;
	}
	float value(ft_stof(data.value));
	if (value > 999) {
		data.error = TOOLARGE;
		return data;
	}
	else if (value < 1) {
		data.error = NOTPOSITIVE;
		return data;
	}
	return data;
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
			std::cout << "Error: bad input" << " => " << data.date << std::endl;
			break ;
		case TOOLARGE:
			std::cout << "Error: too large a number." << std::endl;
			break ;
	}
}

bool	BitcoinExchange::exchange() {
	if (_data.empty() == true)
		return false;

	for (std::deque<t_data>::iterator it = _data.begin(); it != _data.end(); it++) {
		std::stringstream ssFloat(it->value);
		ssFloat >> it->exchanged_value;
		it->exchanged_value *= 
		// TODO : exchange 어떻게?
	}
	return true;
}

void BitcoinExchange::print_exchanging_result() {
	for (std::deque<t_data>::iterator it = _data.begin(); it != _data.end(); it++) {
		print_one_data(*it);
	}
}