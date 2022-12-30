#include <iostream>
#include "Array.hpp"

class A
{
    private :
        char _data;
    public :
        A() {}
        ~A() {}
        void setData(char c) { _data = c; }
        char getData() { return (_data); }
};

int main()
{
    Array<int> arrInt(5);
    for (int i = 0; i < arrInt.size(); i++)
        arrInt[i] = i * 10;
    for (int i = 0; i < arrInt.size(); i++)
        std::cout << "[" << i << "] : " << arrInt[i] << std::endl;
    
    Array<A> arrClass(5);
    for (int i = 0; i < arrClass.size(); i++)
        arrClass[i].setData(i + 'a');
    for (int i = 0; i < arrClass.size(); i++)
        std::cout << "[" << i << "] : " << arrClass[i].getData() << std::endl;
}