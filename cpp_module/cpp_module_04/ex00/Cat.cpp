#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat()" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal()
{
	std::cout << "Cat(copy)" << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	std::cout << "~Cat()" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow !!" << std::endl;
}

std::string Cat::getType() const
{
	return (_type);
}
