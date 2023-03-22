#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	getCSV();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
	_rate = ref._rate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::getCSV() {
	std::string filename(CSVFILE);
	if (filename.length() < 5 || \
		filename.substr(filename.length() - 4) != std::string(".csv")){
		throw InvalidFileException();
		}
	std::fstream readfile(filename);

	if (readfile.is_open() == false) {
		throw InvalidFileException();
	}
	else {
		std::string line;
		int line_num(1);
		while (std::getline(readfile, line))
		{
			if (line_num == 1) {
				if (line != "date,exchange_rate") {
					throw InvalidFileException();
				}
			}
			else {
				if (!validCheckDataLine(line)) {
					std::cout << "Error: line[" << line_num << "] " << line << std::endl;
					throw InvalidFileException();
				}
				else {
					_rate[line.substr(0, 10)] = ftStof(line.substr(11));
				}
			}
			line_num++;
		}
	}
}

const char *BitcoinExchange::InvalidFileException::what() const throw() {
	std::string ret;
	return ("Error: Invalid CSV File");
}

bool BitcoinExchange::validCheckDataLine(std::string &line) {
	if (line.length() < 12) {
		return false;
	}

	// 형식체크
	if (line[4] != '-' || line[7] != '-' || line[10] != ',') {
		return false;
	}

	// 소숫점 체크
	bool used_dot(false);
	for (unsigned int i = 11; i < line.length(); i++) {
		if (std::isdigit(line[i]))
			continue ;
		else if (used_dot == true && line[i] == '.')
			return false;
		else if (!std::isdigit(line[i]) && line[i] != '.')
			return false;
		else if (line[i] != '.')
			used_dot = true;
	}

	// 날짜 체크
	int year(std::atoi(line.substr(0, 4).c_str()));
	int month(std::atoi(line.substr(5, 2).c_str()));
	int day(std::atoi(line.substr(8, 2).c_str()));
	if ((year < 2009 || 2023 < year) || \
		(isLeapYear(year) && month == 2 && (day < 1 || day > 29)) || \
		(month < 1 || month > 12) || \
		(day < 1 || day > 31) || \
		(month == 2 && day > 28) || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		return false;
	}
	return true;
}

float ftStof(std::string str) {
	std::stringstream ssFloat(str);
	float value(0);
	ssFloat >> value;
	return value;
}

bool isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    	return true;
    return false;

}

t_data BitcoinExchange::parseInputLine(std::string &line) {
	t_data data;
	data.error = TRUE;

	if (line.length() < 14) {
		data.error = BADINPUT;
		data.date = line;
		return data;
	}
	int year(std::atoi(line.substr(0, 4).c_str()));
	int month(std::atoi(line.substr(5, 2).c_str()));
	int day(std::atoi(line.substr(8, 2).c_str()));

	data.date = line.substr(0, 10);
	std::string value = line.substr(13);

	if ((line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | ")) {
		data.error = BADINPUT;
		data.date = line;
		return data;
	}

	if ((year < 2009 || 2023 < year) || \
		(isLeapYear(year) && month == 2 && (day < 1 || day > 29)) || \
		(month < 1 || month > 12) || \
		(day < 1 || day > 31) || \
		(month == 2 && day > 28) || \
		((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		data.error = BADINPUT;
		data.date = line;
		return data;
	}
	data.value = ftStof(value);

	if (data.value == 0) {
		if (value.length() != 1 || value[0] != '0')
			data.error = BADINPUT;
			data.date = line;
	}
	else if (data.value > 999) {
		data.error = TOOLARGE;
	}
	else if (data.value < 1) {
		data.error = NOTPOSITIVE;
	}
	return data;
}

void	BitcoinExchange::printOneData(t_data &data) {
	switch (data.error) {
		case TRUE:
			std::cout << data.date << " => " << data.value \
			<< " = " << data.exchanged_value << std::endl;
			break ;
		case NOTPOSITIVE:
			std::cout << "Error: not a positive number." << std::endl;
			break ;
		case BADINPUT:
			std::cout << "Error: bad input" << " => \"" << data.date << "\"" << std::endl;
			break ;
		case TOOLARGE:
			std::cout << "Error: too large a number." << std::endl;
			break ;
	}
}

float BitcoinExchange::findRateValue(std::string &key) {
	std::string year = key.substr(0, 4);
	std::string month = key.substr(5, 2);
	std::string day = key.substr(8, 2);
	std::string valid_date(year + std::string("-") + month + std::string("-") + day);

	while (_rate.find(valid_date) == _rate.end()) {
		if (day == "01") {
			if (month == "01") {
				if (year == "2009") {
					return -1;
				}
				else if (year[3] == '0') {
					year[2] = year[2] - 1;
					year[2] = year[3] - 9;
				}
				else {
					year[3] = year[3] - 1;
				}
				month = "12";
			}
			else if (month == "10") {
				month = "09";
			}
			else {
				month[1] = month[1] - 1;
			}
			day = "31";
		}
		else if (day[1] == '0') {
			day[0] = day[0] - 1;
			day[1] = '9';
		}
		else {
			day[1] = day[1] - 1;
		}
		valid_date = year + std::string("-") + month + std::string("-") + day;
	}
	// std::cout << "<data> : " << valid_date << " ";
	return _rate[valid_date];
}

void	BitcoinExchange::exchange(t_data &data) {
	if (data.error != 1)
		return ;
	float rate_value(findRateValue(data.date));
	if (rate_value == -1)
		data.error = BADINPUT;
	data.exchanged_value = data.value * rate_value;
	// std::cout << "data.value " << data.value << " | _rate[data.date] " << _rate[data.date] << std::endl;
	return ;
}

void BitcoinExchange::exchangingPrint(char *file) {
	std::fstream readfile(file);
	t_data data;

	if (readfile.is_open() == false) {
		std::cout << "Error : Invalid file(argv)" << std::endl;
		return ;
	}

	std::string line;
	int line_num(1);
	while (std::getline(readfile, line))
	{
		data.date.clear();
		data.value = 0;
		data.exchanged_value = 0;
		data.error = 1;
		if (line_num == 1) {
			if (line != "date | value") {
				data.error = BADINPUT;
				data.date = line;
				std::cout << "[" << line_num << "] ";
				printOneData(data);
				return ;
			}
		}
		else {
			data = parseInputLine(line);
			exchange(data);
			std::cout << "[" << line_num << "] ";
			printOneData(data);
		}
		line_num++;
		// std::cout << "LINE["<< line_num << "] " << line << std::endl;
	}
}