#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void    iter(T *arr, int length, void (*f)(T&))
{
    for (int i = 0; i < length; i++)
        f(arr[i]);
    // std::cout << "\ngeneral version" << std::endl;
}

template <typename T>
void    iter(const T *arr, int length, void (*f)(const T&))
{
    for (int i = 0; i < length; i++)
        f(arr[i]);
    // std::cout << "\nconst version" << std::endl;
}


#endif
