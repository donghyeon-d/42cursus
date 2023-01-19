#include <iostream>
#include "iter.hpp"
#include "func.hpp"
#include "Data.hpp"
#define LENGTH 5

int main()
{
    {
        std::cout << "< --- int test --- >" << std::endl;
        int *arr = new int[LENGTH];
        for (int i = 0; i < LENGTH; i++)
            arr[i] = i;
        std::cout << "[print one]" << std::endl;
        iter(arr, LENGTH, printOne);
        iter(arr, LENGTH, increament);
        std::cout << "\n[after increament print one]" << std::endl;
        iter(arr, LENGTH, printOne);
    }

    {
        std::cout << "\n\n< --- const int test --- >" << std::endl;
        const int arr[5] = {0, 1, 2, 3, 4};
        std::cout << "[print one]" << std::endl;
        iter(arr, LENGTH, printOne);
    }

    {
        std::cout << "\n\n< --- Class Data test --- >" << std::endl;
        Data data[5];
        for (int i = 0; i < 5; i++)
            data[i].setNum(i);
        std::cout << "[print one]" << std::endl;
        iter(data, LENGTH, printOne);
        iter(data, LENGTH, increament);
        std::cout << "\n[after increament print one]" << std::endl;
        iter(data, LENGTH, printOne);
    }
    return (0);
}