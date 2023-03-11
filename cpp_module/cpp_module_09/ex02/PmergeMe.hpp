#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <cctype>
#include <exception>
#include <ctime>
#include <algorithm>

class PmergeMe {
	private:
		char **_numbers;
		std::vector<int> _vec_before_sort;
		std::vector<int> _vec_sequence;
		std::vector<int> _vec_after_sort;
		std::list<int> _list_before_sort;
		std::list<int> _list_sequence;
		std::list<int> _list_after_sort;
		double _vec_time;
		double _list_time;
		bool numbersValidCheck();
		class InvalidArgvException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		PmergeMe();
		// PmergeMe(char **argv);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe* rhs);
		~PmergeMe();
		void setNumbers(char **argv);
		void diff();
};

#endif