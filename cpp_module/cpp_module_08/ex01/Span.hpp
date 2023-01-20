#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>

class Span
{
	private:
		std::vector<int> arr_;
		unsigned int max_size_;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &span);
		Span &operator=(const Span &span);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void printAll();
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
