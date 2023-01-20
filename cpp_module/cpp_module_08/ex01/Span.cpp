#include <iostream>
#include "Span.hpp"

Span::Span() : max_size_(0)
{}

Span::Span(unsigned int N) : max_size_(N)
{}

Span::Span(const Span &span) : max_size_(span.max_size_)
{
	arr_ = span.arr_;
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return (*this);
	if (max_size_ < span.max_size_)
		throw exceptionFullStore();
	arr_ = span.arr_;
	return (*this);
}

void Span::addNumber(int number)
{
	
	if(arr_.size() < max_size_)
		arr_.push_back(number);
	else
		throw exceptionFullStore();
}

void Span::printAll()
{
	for (std::vector<int>::iterator itr = arr_.begin(); itr != arr_.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

int Span::shortestSpan()
{
	if (arr_.size() == 0)
		throw exceptionEmptyStore();
	if (arr_.size() == 1)
		throw exceptionNoSpan();

	std::vector<int> temp = arr_;
	sort(temp.begin(), temp.end());
	int min(INT_MAX);
	for (unsigned int i = 0; i < temp.size() - 1; i++)
	{
		if (min > temp[i + 1] - temp[i])
			min = temp[i + 1] - temp[i];
	}
	return (min);
}

int Span::longestSpan()
{
	if (arr_.size() == 0)
		throw exceptionEmptyStore();
	if (arr_.size() == 1)
		throw exceptionNoSpan();
	int max = *(std::max_element(arr_.begin(), arr_.end()));
	int min = *(std::min_element(arr_.begin(), arr_.end()));
	return(max - min);
}

void Span::fillRange(unsigned int begin_idx, unsigned int end_idx, int num)
{
	if (max_size_ < end_idx + 1)
		throw exceptionFullStore();
	unsigned int count(end_idx - begin_idx + 1);
	if (arr_.size() < begin_idx + count)
		arr_.resize(begin_idx + count);
	std::vector<int>::iterator begin = arr_.begin();
	begin += begin_idx;
	std::vector<int>::iterator end = begin + count;
	std::fill(begin, end, num);
}
