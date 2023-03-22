#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _numbers(NULL) {

}

PmergeMe::PmergeMe(const PmergeMe& rhs) : _numbers(NULL) {
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe* rhs) {
	this->_numbers = rhs->_numbers;
	this->_vec = rhs->_vec;
	this->_deq = rhs->_deq;
	this->_set = rhs->_set;
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

void PmergeMe::printSet() {
	for (std::set<int>::iterator it = _set.begin(); it != _set.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::setNumbers(char **argv) {
	int i(1);
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
		i++;
	}
	_numbers = &argv[1];
	return true;
}

void PmergeMe::setVec() {
	if (_numbers == NULL)
		return ;
	_set.clear();
	int i(0), tmp(0);
	double dtmp;
	while (_numbers[i] != '\0') {
		dtmp = ft_atod(_numbers[i]);
		tmp = static_cast<int>(dtmp);
		_vec.push_back(tmp);
		i++;
	}
}

void PmergeMe::setDeq() {
	if (_numbers == NULL)
		return ;
	_set.clear();
	int i(0), tmp(0);
	double dtmp;
	while (_numbers[i] != '\0') {
		dtmp = ft_atod(_numbers[i]);
		tmp = static_cast<int>(dtmp);
		_deq.push_back(tmp);
		i++;
	}
}

double ft_atod(char *str) {
	std::string s(str);
	std::stringstream ssDouble(s);
	double value(0);
	ssDouble >> value;
	return value;
}

void PmergeMe::insertSortVec(std::vector<int> &vec, int left, int right) {
	int pick;
	int j(0);

	for (int i = left + 1; i < right + 1; i++) {
		j = i;
		pick = vec[j];
		while (j > left && pick < vec[j - 1]) {
			vec[j] = vec[j - 1];
			j--;
		}
		if (i != j)
			vec[j] = pick;
	}
}

void PmergeMe::insertSortDeq(std::deque<int> &deq, int left, int right) {
	int pick;
	int j(0);

	for (int i = left + 1; i < right + 1; i++) {
		j = i;
		pick = deq[j];
		while (j > left && pick < deq[j - 1]) {
			deq[j] = deq[j - 1];
			j--;
		}
		if (i != j)
			deq[j] = pick;
	}
}

void PmergeMe::sortVec(std::vector<int> &array, int left, int right) {
    if (right - left > CNT) {
        int mid = (left + right) / 2;
        sortVec(array, left, mid);
        sortVec(array, mid + 1, right);
        mergeVec(array, left, mid, right);
    } else {
        insertSortVec(array, left, right);
    }
}

void PmergeMe::sortDeq(std::deque<int> &array, int left, int right) {
    if (right - left > CNT) {
        int mid = (left + right) / 2;
        sortDeq(array, left, mid);
        sortDeq(array, mid + 1, right);
        mergeDeq(array, left, mid, right);
    } else {
        insertSortDeq(array, left, right);
    }
}

void PmergeMe::mergeVec(std::vector<int> &array, int left, int mid, int right) {
	std::vector<int> left_vec, right_vec;
	for (int i = left; i < mid + 1; i++) {
		left_vec.push_back(array[i]);
	}
	for (int i = mid + 1; i < right + 1; i++) {
		right_vec.push_back(array[i]);
	}

	int left_idx(0);
	int right_idx(0);
	int left_end(left_vec.size());
	int right_end(right_vec.size());
	for (int i = left; i < right + 1; i++) {
		if (left_idx == left_end) {
			array[i] = right_vec[right_idx];
			right_idx++;
		}
		else if (right_idx == right_end) {
			array[i] = left_vec[left_idx];
			left_idx++;
		}
		else if (left_vec[left_idx] < right_vec[right_idx]) {
			array[i] = left_vec[left_idx];
			left_idx++;
		}
		else {
			array[i] = right_vec[right_idx];
			right_idx++;
		}
	}
}

void PmergeMe::mergeDeq(std::deque<int> &array, int left, int mid, int right) {
	std::deque<int> left_que, right_que;
	for (int i = left; i < mid + 1; i++) {
		left_que.push_back(array[i]);
	}
	for (int i = mid + 1; i < right + 1; i++) {
		right_que.push_back(array[i]);
	}

	int left_idx(0);
	int right_idx(0);
	int left_end(left_que.size());
	int right_end(right_que.size());
	for (int i = left; i < right + 1; i++) {
		if (left_idx == left_end) {
			array[i] = right_que[right_idx];
			right_idx++;
		}
		else if (right_idx == right_end) {
			array[i] = left_que[left_idx];
			left_idx++;
		}
		else if (left_que[left_idx] < right_que[right_idx]) {
			array[i] = left_que[left_idx];
			left_idx++;
		}
		else {
			array[i] = right_que[right_idx];
			right_idx++;
		}
	}
}

void PmergeMe::sortSet() {
	int i(0), tmp(0);
	double dtmp;
	while (_numbers[i] != '\0') {
		dtmp = ft_atod(_numbers[i]);
		if (dtmp > 2147483647 || dtmp < -2147483648) {
			std::cout << "Error : _numbers[" << i << "]=" << _numbers[i] << " is too large or too small" << std::endl;
			_set.clear();
			return ;
		}
		else if (dtmp == 0 && _numbers[i][0] != '0') {
			std::cout << "Error : _numbers[" << i << "]=" << _numbers[i] << " is not integer" << std::endl;
			_set.clear();
			return ;
		}
		else
			tmp = static_cast<int>(dtmp);
		_set.insert(tmp);
		i++;
	}
}

std::vector<int> &PmergeMe::getVec() {
	return _vec;
}

std::deque<int> &PmergeMe::getDeq() {
	return _deq;
}

char **PmergeMe::getNumbers() {
	return _numbers;
}