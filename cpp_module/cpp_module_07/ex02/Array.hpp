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
        Array();
        Array(const unsigned int n);
        Array(const Array &array);
        Array& operator=(const Array &array);
        ~Array();

        class ArrayInvalidIndexException : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Invalid index");
                }
        };

        const T& operator[](const unsigned int idx) const;
        T& operator[](const unsigned int idx);
        unsigned int size() const;
        void    displayArray() const;
};

#include "Array.tpp"

#endif