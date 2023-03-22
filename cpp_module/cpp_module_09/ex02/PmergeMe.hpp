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
#define CNT 5

class PmergeMe {
	private:
		char **_numbers;
		std::vector<int> _vec;
		std::deque<int> _deq;
		void mergeVec(std::vector<int> &array, int left, int mid, int right);
		class InvalidArgvException : public std::exception
        {
            public :
                const char *what() const throw();
        };
	public:
		void printVec();
		void printDeq();
		void printNum();
		void insertSortVec(std::vector<int> &vec, int left, int right);
		void insertSortDeq(std::deque<int> &deq);
		void sortVec(std::vector<int> &array, int left, int right);
		std::vector<int> &getVec();
		std::deque<int> &getDeq();
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe* rhs);
		~PmergeMe();
		bool setNumbers(char **argv);
		
};

double ft_atod(char *str);

#endif