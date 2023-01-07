#include <iostream>
#include "iter.hpp"
#define LENGTH 5

void printArr(int arr[], int length)
{
    std::cout << "[func printArr]" << std::endl;
    for (int i = 0; i < length; i++)
        std::cout << "[" << i << "] : " << arr[i] << std::endl;
}

void printOne(const int i)
{
    std::cout << i << std::endl;
}

void multipleTen(int &i)
{
    i *= 10;
}

void pointer(int *i)
{
    std::cout << "pointer : " << i << std::endl;
}

int main()
{
    {
        std::cout << "< --- int test --- >" << std::endl;
        int *arr = new int[LENGTH];
        for (int i = 0; i < LENGTH; i++)
            arr[i] = i;
        printArr(arr, LENGTH);

        iter(arr, LENGTH, printOne); // variable
        iter(arr, LENGTH, multipleTen); // reference
        iter(arr, LENGTH, printOne); // variable
        iter(arr, LENGTH, pointer); // pointer
    }

    {
        std::cout << "\n\n< --- const int test --- >" << std::endl;
        const int arr[LENGTH] = {0,1,2,3,4};

        iter(arr, LENGTH, printOne);
    }

    return (0);
}