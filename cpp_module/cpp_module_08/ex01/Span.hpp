#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

class Span
{
	private:
		std::vector<int> arr_;
		unsigned int max_size_;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &span);
		std::vector<int>::iterator getBegin();
		std::vector<int>::const_iterator getBegin() const;
		std::vector<int>::iterator getEnd();
		std::vector<int>::const_iterator getEnd() const;
		Span &operator=(const Span &span);
		void addNumber(int number);
		void setMaxSize(unsigned int N);
		unsigned int getMaxSize() const;
		int shortestSpan();
		int longestSpan();
		void printAll() const;
		void fillRange(unsigned int begin_idx, unsigned int end_idx, int num);

		class exceptionFullStore : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Full store");
				}
		};
		
		class exceptionEmptyStore : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Empty store");
				}
		};

		class exceptionWrongRange : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Wrong range");
				}
		};

		class exceptionNoSpan : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("No span can be found");
				}
		};
};

#endif
