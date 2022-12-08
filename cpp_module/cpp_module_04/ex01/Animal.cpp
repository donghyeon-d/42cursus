#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal()" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal(copy)" << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "~Animal()" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	_type = animal._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal instance can't make sound" << std::endl;
}

std::string Animal::getType() const
{
	std::cout << "Animal has no type" << std::endl;
	return (_type);
}
