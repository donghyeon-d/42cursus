#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _numbers(0), _vec_time(0), _list_time(0), _set_time(0) {
	
}

void PmergeMe::setNumbers(char **argv) {
	_numbers = &(argv[1]);
	if (numbersValidCheck() == false) {
		throw InvalidArgvException();
	}
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe* rhs) {
	_numbers = rhs->_numbers;
	_vec_sequence = rhs->_vec_sequence;
	_list_sequence = rhs->_list_sequence;
	_set_sequence = rhs->_set_sequence;
	_vec_time = rhs->_vec_time;
	_list_time = rhs->_list_time;
	_set_time = rhs->_set_time;
	return *this;
}

PmergeMe::~PmergeMe() {
	
}

bool PmergeMe::numbersValidCheck() {
	if (_numbers == NULL) {
		return false;
	}
	int i(0), j(0);
	while (_numbers[i] != NULL) {
		j = 0;
		while (_numbers[i][j] != '\0') {
			if (std::isdigit(_numbers[i][j]) == false)
				return false;
			j++;
		}
		i++;
	}
	return true;
}

const char *PmergeMe::InvalidArgvException::what() const throw() {
	return "Error: Invalid Argv";
}

void PmergeMe::timeCheckSet() {
	if (_numbers == NULL)
		return ;
	clock_t start(0), finish(0);
	start = std::clock();
	int i(0);
	while (_numbers[i] != NULL) {
		_set_sequence.insert(std::atoi(_numbers[i]));
		i++;
	}
	finish = std::clock();
	_set_time = static_cast<double>(finish - start);
}

void PmergeMe::timeCheckVector() {
	if (_numbers == NULL)
		return ;
	clock_t start(0), finish(0);
	start = std::clock();
	int i(0);
	while (_numbers[i] != NULL) {
		_vec_sequence.push_back(std::atoi(_numbers[i]));
		i++;
	}
	std::sort(_vec_sequence.begin(), _vec_sequence.end());
	finish = std::clock();
	_vec_time = static_cast<double>(finish - start);
}

void PmergeMe::timeCheckList() {
	if (_numbers == NULL)
		return ;
	clock_t start(0), finish(0);
	start = std::clock();
	int i(0);
	while (_numbers[i] != NULL) {
		_list_sequence.push_back(std::atoi(_numbers[i]));
		i++;
	}
	_list_sequence.sort();
	finish = std::clock();
	_list_time = static_cast<double>(finish - start);
}


void PmergeMe::printDiff() {
	std::cout << "Before: ";
	for (int i = 0; _numbers[i] != NULL; i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vec_sequence.begin(); it != _vec_sequence.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout.precision(3);
	std::cout << "Time to process a range of " << _vec_sequence.size() << " elements with std::vector<int> : " << _vec_time << " ms" << std::endl;
	std::cout << "\t=> ";
	for (std::vector<int>::iterator it = _vec_sequence.begin(); it != _vec_sequence.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _list_sequence.size() << " elements with std::list<int> : " << _list_time << " ms" << std::endl;
	std::cout << "\t=> ";
	for (std::list<int>::iterator it = _list_sequence.begin(); it != _list_sequence.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _set_sequence.size() << " elements with std::set<int> : " << _set_time << " ms" << std::endl;
	std::cout << "\t=> ";
	for (std::set<int>::iterator it = _set_sequence.begin(); it != _set_sequence.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}