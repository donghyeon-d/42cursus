// #include "Data.hpp"

class Data
{
    private :
        int _data;

    public :
        Data();
        Data(int data);
        Data(Data const &data);
        ~Data();
        Data &operator=(Data const &data);
        int getData() const;
        void setData(int newData);
};


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

