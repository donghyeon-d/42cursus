#include <iostream>
#include "iter.hpp"
#define LENGTH 5

void print_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        std::cout << "[" << i << "] : " << arr[i] << std::endl;
}

void print_one(int &i)
{
    std::cout << i << std::endl;
}

void print_one(const int &i)
{
    std::cout << i << std::endl;
}

void mul_ten(int &i)
{
    i *= 10;
}

int main()
{
    {
        std::cout << "< --- int test --- >" << std::endl;
        int *arr = new int[LENGTH];
        for (int i = 0; i < LENGTH; i++)
            arr[i] = i;
        print_arr(arr, LENGTH);

        iter(arr, LENGTH, mul_ten);

        print_arr(arr, LENGTH);
    }

    {
        std::cout << "\n\n< --- const int test --- >" << std::endl;
        const int arr[LENGTH] = {0,1,2,3,4};

        iter(arr, LENGTH, print_one);
    }

    return (0);
}