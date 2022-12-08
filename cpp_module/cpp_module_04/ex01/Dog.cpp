#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog()" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog(copy)" << std::endl;
	_brain = new Brain();
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "~Cat()" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog.getType();
	_brain = dog._brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark !!" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}
