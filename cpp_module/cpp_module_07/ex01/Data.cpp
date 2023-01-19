#include "Data.hpp"

Data::Data() : _num(0)
{
}

Data::Data(const Data &data)
{
	if (this != &data)
		*this = data;
}

Data &Data::operator=(const Data &data)
{
	setNum(data.getNum());
	return (*this);
}

Data::~Data()
{
}

Data Data::operator++(int x)
{
	x++;
	Data temp(*this);
	setNum(_num + 1);
	return (temp);
}

void Data::setNum(int num)
{
	this->_num = num;
}

int Data::getNum() const
{
	return (this->_num);
}

std::ostream& operator<<( std::ostream& os, const Data &ref )
{
	os << ref.getNum();
	return os;
}