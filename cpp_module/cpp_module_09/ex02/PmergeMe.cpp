#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe* rhs) {
	this->_numbers = rhs->_numbers;
	this->_vec = rhs->_vec;
	this->_deq = rhs->_deq;
	return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::printVec() {
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void PmergeMe::printDeq() {
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printNum() {
	int i(0);
	while (_numbers[i] != NULL) {
		std::cout << _numbers[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

bool PmergeMe::setNumbers(char **argv) {
	int i(1), tmp(0);
	double dtmp;
	while (argv[i] != '\0') {
		dtmp = ft_atod(argv[i]);
		if (dtmp > 2147483647 || dtmp < -2147483648) {
			std::cout << "Error : argv[" << i << "]=" << argv[i] << " is too large or too small" << std::endl;
			return false;
		}
		else if (dtmp == 0 && argv[i][0] != '0') {
			std::cout << "Error : argv[" << i << "]=" << argv[i] << " is not integer" << std::endl;
			return false;
		}
		else
			tmp = static_cast<int>(dtmp);
		_vec.push_back(tmp);
		_deq.push_back(tmp);
		i++;
	}
	_numbers = &argv[1];
	return true;
}

double ft_atod(char *str) {
	std::string s(str);
	std::stringstream ssDouble(s);
	double value(0);
	ssDouble >> value;
	return value;
}

void PmergeMe::insertSortVec() {
	int tmp;

	for (unsigned int i = 1; i < _vec.size(); i++) {
		for (unsigned int j = i; j > 0; j--) {
			if (_vec[j] < _vec[j - 1]) {
				tmp = _vec[j - 1];
				_vec[j - 1] = _vec[j];
				_vec[j] = tmp;
			}
			else
				continue ;
		}
	}
	std::cout << "vec : "; printVec();
}

void PmergeMe::insertSortDeq() {
	int tmp;

	for (unsigned int i = 1; i < _deq.size(); i++) {
		for (unsigned int j = i; j > 0; j--) {
			if (_deq[j] < _deq[j - 1]) {
				tmp = _deq[j - 1];
				_deq[j - 1] = _deq[j];
				_deq[j] = tmp;
			}
			else
				continue ;
		}
	}
	std::cout << "deq : "; printDeq();
}