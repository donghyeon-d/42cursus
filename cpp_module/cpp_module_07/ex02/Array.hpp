#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T>
class Array
{
    private :
        T *_arr;
        unsigned int _size;

    public :
        Array() : _arr(0), _size(0)
        {}

        Array(unsigned int n)  : _arr(new T[n]), _size(n)
        {}

        Array(const Array &array)
        {
            *this = array;
        }

        Array& operator=(const Array &array)
        {
            if (_arr != 0)
                delete[] _arr;
            _size = array._size;
            _arr = new T[_size];
            for (int i = 0; i < array._size; i++)
                _arr[i] = array._arr[i];
            return (*this);
        }

        ~Array()
        {
            if (_arr != 0)
                delete[] _arr;
        }

        class ArrayInvalidIndexException : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Invalid index");
                }
        };

        T operator[](unsigned int idx)
        {
            if (_arr == 0 || idx > _size - 1)
                throw ArrayInvalidIndexException();
            else
                return (_arr[idx]);
        }
        
        int size() const
        {
            return (_size);
        }
};

#endif