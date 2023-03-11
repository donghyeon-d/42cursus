#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _numbers(NULL), _vec_time(0), _list_time(0) {
	
}

// PmergeMe::PmergeMe(char **argv) : _vec_time(0), _list_time(0) {
// 	_numbers = &(argv[1]);
// 	if (numbersValidCheck() == false) {
// 		throw InvalidArgvException();
// 	}
// 	int i(0);
// 	while (_numbers[i] != NULL) {
// 		_vec_before_sort.push_back(std::atoi(_numbers[i]));
// 		_list_before_sort.push_back(std::atoi(_numbers[i]));
// 	}
// }

void PmergeMe::setNumbers(char **argv) {
	_numbers = &(argv[1]);
	if (numbersValidCheck() == false) {
		throw InvalidArgvException();
	}
	int i(0);
	while (_numbers[i] != NULL) {
		_vec_before_sort.push_back(std::atoi(_numbers[i]));
		_list_before_sort.push_back(std::atoi(_numbers[i]));
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe* rhs) {
	_numbers = rhs->_numbers;
	_vec_before_sort = rhs->_vec_before_sort;
	_vec_sequence = rhs->_vec_sequence;
	_vec_after_sort = rhs->_vec_after_sort;
	_list_before_sort = rhs->_list_before_sort;
	_list_sequence = rhs->_list_sequence;
	_list_after_sort = rhs->_list_after_sort;
	_vec_time = rhs->_vec_time;
	_list_time = rhs->_list_time;
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

void PmergeMe::diff() {
	if (_numbers == NULL || numbersValidCheck() == false) {
		return ;
	}
	// vector time check
	clock_t start(0), finish(0);
	start = clock();
	std::vector<int>::iterator vec_it = _vec_before_sort.begin();
	std::vector<int>::iterator vec_it_next = _vec_before_sort.begin()++;
	// while (vec_it != _vec_before_sort.end()) {
	// 	std::merge(_vec_sequence.begin(), _vec_sequence.end(), vec_it, vec_it_next, _vec_after_sort.begin());
	// 	_vec_sequence = _vec_after_sort;
	// 	_vec_after_sort.clear();
	// 	vec_it++;
	// 	if (vec_it_next != _vec_before_sort.end())
	// 		vec_it_next++;
	// }
	while (vec_it != _vec_before_sort.end()) {
		std::merge(_vec_sequence.begin(), _vec_sequence.end(), vec_it, vec_it_next, _vec_after_sort.begin());
		_vec_sequence = _vec_after_sort;
		// _vec_after_sort.clear();
		vec_it++;
		if (vec_it_next != _vec_before_sort.end())
			vec_it_next++;
	}
	_vec_after_sort = _vec_sequence;
	finish = clock();
	_vec_time = start - finish;

	// list time check
	start = clock();
	std::list<int>::iterator list_it = _list_before_sort.begin();
	std::list<int>::iterator list_it_next = (_list_before_sort.begin())++;
	while (list_it != _list_before_sort.end()) {
		std::merge(_list_sequence.begin(), _list_sequence.end(), list_it, list_it_next, _list_after_sort.begin());
		_list_sequence = _list_after_sort;
		_list_after_sort.clear();
		list_it++;
		if (list_it_next != _list_before_sort.end())
			list_it_next++;
	}
	_vec_after_sort = _vec_sequence;
	finish = clock();
	_list_time = start - finish;

	// print
	std::cout << "Before: ";
	for (std::vector<int>::iterator before_it = _vec_before_sort.begin(); before_it != _vec_before_sort.end(); before_it++) {
		std::cout << *before_it << " ";
	}
	std::cout << std::endl;

	std::cout << "vector After: ";
	for (std::vector<int>::iterator after_it = _vec_after_sort.begin(); after_it != _vec_after_sort.end(); after_it++) {
		std::cout << *after_it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "list After: ";
	for (std::list<int>::iterator after_it = _list_after_sort.begin(); after_it != _list_after_sort.end(); after_it++) {
		std::cout << *after_it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec_after_sort.size() << " elements with std::vector<int> : " << _vec_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << _vec_after_sort.size() << " elements with std::list<int> : " << _list_time << " ms" << std::endl;
}