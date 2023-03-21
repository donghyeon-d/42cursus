#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <cctype>
#include <deque>
#include <vector>
#include <string>
#include <sstream>

class PmergeMe {
	private:
		char **_numbers;
		std::vector<int> _vec;
		std::deque<int> _deq;
		void printVec();
		void printDeq();
		void printNum();
		class InvalidArgvException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		void insertSortVec();
		void insertSortDeq();
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe* rhs);
		~PmergeMe();
		bool setNumbers(char **argv);
		
};

double ft_atod(char *str);

#endif