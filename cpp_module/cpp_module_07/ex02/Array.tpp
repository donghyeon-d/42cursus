#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0)
{
    // std::cout << "Array()" << std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int n)  : _arr(new T[n]), _size(n)
{
    // std::cout << "Array(n)" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &array) : _arr(0), _size(0)
{
    // std::cout << "Array(copy)" << std::endl;
    if (this != &array)
        *this = array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &array)
{
    // std::cout << "Array(==)" << std::endl;
    if (_arr != 0)
        delete[] _arr;
    _size = array.size();
    _arr = new T[_size];
    for (unsigned int i = 0; i < array.size(); i++)
        _arr[i] = array._arr[i];
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    if (_arr != 0)
        delete[] _arr;
}

template <typename T>
const T& Array<T>::operator[](const unsigned int idx) const
{
    if (idx > _size - 1)
        throw ArrayInvalidIndexException();
    else
        return (_arr[idx]);
}

template <typename T>
T& Array<T>::operator[](const unsigned int idx)
{
    if (idx > _size - 1)
        throw ArrayInvalidIndexException();
    else
        return (_arr[idx]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
void    Array<T>::displayArray() const
{
    for (unsigned int i = 0; i < _size; i++)
    {
        std::cout << "[" << i << "] : " << _arr[i] << std::endl;
    }
}

#endif
