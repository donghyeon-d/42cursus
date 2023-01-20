#include <iostream>
#include "Array.hpp"

// int main()
// {
//     Array<int> num1(5);
//     for (int i = 0; i < 5; i++)
//         num1[i] = i;
//     num1.displayArray();
//     Array<int> num2(num1);
//     num2.displayArray();

//     const Array<int> cnum1(num1);
//     num1.displayArray();
//     const int ca1 = num1[1];
//     const int ca2 = cnum1[1];
//     int a1 = num1[1];
//     int a2 = cnum1[1];

//     std::cout << "ca1 : " << ca1 << ", ca2 : " << ca2 << std::endl;
//     std::cout << "a1 : " << a1 << ", a2 : " << a2 << std::endl;
// }


#define MAX_VAL 10
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << "numbers : " << numbers[i] << " | " << mirror[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int j = 0; j < MAX_VAL;j++)
            std::cout << "numbers : " << numbers[j] << " | " << mirror[j] << " | " 
            << tmp[j] << " | " << test[j] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[-2] : " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[MAX_VAL] : " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}