#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog()" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog(copy)" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "~Cat()" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bow wow !!" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}
