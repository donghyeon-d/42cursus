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
    Data *origin = new Data;
    origin->_data = 10;
    Data *ptr;
    uintptr_t serial = serialize(origin);
    ptr = deserialize(serialize(origin));

    std::cout << origin << std::endl;
    std::cout << ptr << std::endl;
    std::cout << serial << std::endl;
    std::cout << "origin : " << origin->_data << std::endl;
    std::cout << "ptr : " << ptr->_data << std::endl;
    delete origin;
}
