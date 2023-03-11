#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <algorithm>
#include <list>
#include <vector>
#include <set>

class PmergeMe {
	private:
		char **_numbers;
		std::vector<int> _vec_sequence;
		std::list<int> _list_sequence;
		std::set<int> _set_sequence;
		double _vec_time;
		double _list_time;
		double _set_time;
		bool numbersValidCheck();
		class InvalidArgvException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe* rhs);
		~PmergeMe();
		void setNumbers(char **argv);
		void printDiff();
		void timeCheckSet();
		void timeCheckVector();
		void timeCheckList();
};

#endif