#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void    iter(T *arr, int length, void (*f)(T&))
{
    for (int i = 0; i < length; i++)
        f(arr[i]);
}

#endif
