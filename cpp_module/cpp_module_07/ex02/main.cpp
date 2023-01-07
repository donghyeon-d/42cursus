// #include <iostream>
// #include "Array.hpp"

// class A
// {
//     private :
//         char _data;
//     public :
//         A() {}
//         ~A() {}
//         void setData(char c) { _data = c; }
//         char getData() { return (_data); }
// };

// int main()
// {
    // {
    // int *a = new int();
    // std::cout << *a << std::endl;

    // Array<int> arrA(5);
    // for (int i = 0; i < 5; i++)
    //     arrA[i] = i;
    // const Array<int> arrB(arrA);
    // arrA.displayArray();
    // arrB.displayArray();
    // std::cout << arrA[1] << std::endl;
    // std::cout << arrB[1] << std::endl;
    // arr.displayArray();

    // }

    // Array<int> arrInt(5);
    // for (int i = 0; i < arrInt.size(); i++)
    //     arrInt[i] = i * 10;
    // for (int i = 0; i < arrInt.size(); i++)
    //     std::cout << "[" << i << "] : " << arrInt[i] << std::endl;
    
    // Array<A> arrClass(5);
    // for (int i = 0; i < arrClass.size(); i++)
    //     arrClass[i].setData(i + 'a');
    // for (int i = 0; i < arrClass.size(); i++)
    //     std::cout << "[" << i << "] : " << arrClass[i].getData() << std::endl;


    // const Array<int> arrInt(5);
    // for (unsigned int i = 0; i < arrInt.size(); i++)
    //     arrInt[i] = i * 10;
    // for (unsigned int i = 0; i < arrInt.size(); i++)
    //     std::cout << "[" << i << "] : " << arrInt[i] << std::endl;
// }





#include <iostream>
#include "Array.hpp"

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
            std::cout << "numbers : " << numbers[j] << " | " << mirror[j] << std::endl;
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
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}