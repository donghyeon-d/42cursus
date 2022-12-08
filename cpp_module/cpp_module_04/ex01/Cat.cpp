#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat()" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat(copy)" << std::endl;
	_brain = new Brain();
	*this = cat;
}

Cat::~Cat()
{
	std::cout << "~Cat()" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat.getType();
	_brain = cat._brain;
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
