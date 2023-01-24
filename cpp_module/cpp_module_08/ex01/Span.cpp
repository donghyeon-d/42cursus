#include "Span.hpp"

Span::Span() : max_size_(0)
{}

Span::Span(unsigned int N) : max_size_(N)
{}

Span::Span(const Span &span) : max_size_(span.max_size_)
{	arr_ = span.arr_;	}

std::vector<int>::iterator Span::getBegin() 
{	return (arr_.begin());	}

std::vector<int>::const_iterator Span::getBegin() const
{	return (arr_.begin());	}

std::vector<int>::iterator Span::getEnd()
{	return (arr_.end());	}

std::vector<int>::const_iterator Span::getEnd() const
{	return (arr_.end());	}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return (*this);
	setMaxSize(span.getMaxSize());
	for (std::vector<int>::const_iterator itr = span.getBegin(); itr != span.getEnd(); itr++)
		addNumber(*itr);
	return (*this);
}

void Span::addNumber(int number)
{
	
	if(arr_.size() < max_size_)
		arr_.push_back(number);
	else
		throw exceptionFullStore();
}

void Span::setMaxSize(unsigned int N)
{	max_size_ = N;	}

unsigned int Span::getMaxSize() const
{	return (max_size_);	}

void Span::printAll() const
{
	for (std::vector<int>::const_iterator itr = getBegin(); itr != getEnd(); itr++)
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
	if (max_size_ < end_idx + 1 || begin_idx > end_idx)
		throw exceptionWrongRange();
	unsigned int count(end_idx - begin_idx + 1);
	if (arr_.size() < begin_idx + count)
		arr_.resize(begin_idx + count);
	std::vector<int>::iterator begin = arr_.begin();
	begin += begin_idx;
	std::vector<int>::iterator end = begin + count;
	std::fill(begin, end, num);
}
