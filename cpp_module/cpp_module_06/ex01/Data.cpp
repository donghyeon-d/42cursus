#include "Data.hpp"

Data::Data()
{
}

Data::Data(int data) : _data(data)
{
}

Data::Data(Data const &data)
{
    *this = data;
}

Data::~Data()
{
}

Data &Data::operator=(Data const &data)
{
    _data = data._data;
    return (*this);
}

int Data::getData() const
{
    return (_data);
}

void Data::setData(int newData)
{
    _data = newData;
}

