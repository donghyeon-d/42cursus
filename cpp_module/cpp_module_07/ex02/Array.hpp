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
        {
            std::cout << "Array()" << std::endl;
        }

        Array(unsigned int n)  : _arr(new T[n]), _size(n)
        {std::cout << "Array(n)" << std::endl;}

        Array(const Array &array) : _arr(0), _size(0)
        {
            std::cout << "Array(copy)" << std::endl;
            *this = array;
        }

        Array& operator=(const Array &array)
        {
            std::cout << "Array(==)" << std::endl;
            if (_arr != 0)
                delete[] _arr;
            _size = array._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < array.size(); i++)
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

        const T& operator[](unsigned int idx) const
        {
            if (idx > _size - 1)
                throw ArrayInvalidIndexException();
            else
                return (_arr[idx]);
        }

        T& operator[](unsigned int idx)
        {
            if (idx > _size - 1)
                throw ArrayInvalidIndexException();
            else
                return (_arr[idx]);
        }
        

        unsigned int size() const
        {
            return (_size);
        }

        void    displayArray() const
        {
            for (int i = 0; i < static_cast<int>(_size); i++)
            {
                std::cout << "[" << i << "] : " << _arr[i] << std::endl;
            }
        }
};



#endif