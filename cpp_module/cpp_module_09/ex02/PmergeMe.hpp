#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <cctype>
#include <vector>
#include <deque>
#include <set>
#include <string>
#include <sstream>

#define CNT 5

class PmergeMe {
	private:
		char **_numbers;
		std::vector<int> _vec;
		std::deque<int> _deq;
		std::set<int> _set;
		void mergeVec(std::vector<int> &array, int left, int mid, int right);
		void mergeDeq(std::deque<int> &array, int left, int mid, int right);
		void insertSortVec(std::vector<int> &vec, int left, int right);
		void insertSortDeq(std::deque<int> &deq, int left, int right);
		class InvalidArgvException : public std::exception
        {
            public :
                const char *what() const throw();
        };

	public:
		void printNum();
		void printVec();
		void printDeq();
		void printSet();
		void sortVec(std::vector<int> &array, int left, int right);
		void sortDeq(std::deque<int> &array, int left, int right);
		void sortSet();
		std::vector<int> &getVec();
		std::deque<int> &getDeq();
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe* rhs);
		~PmergeMe();
		bool setNumbers(char **argv);
		char **getNumbers();
};

double ft_atod(char *str);

#endif