#include <cstdint>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data *a = new Data(10);
    Data *p;
    uintptr_t a1 = serialize(a);
    p = deserialize(serialize(a));

    std::cout << a1 << std::endl;
    std::cout << "a : " << a->getData() << std::endl;
    std::cout << "p : " << p->getData() << std::endl;
}