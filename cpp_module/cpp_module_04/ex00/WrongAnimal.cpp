#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal()" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal(copy)" << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "~WrongAnimal()" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	_type = animal._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal instance can't make sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	std::cout << "WrongAnimal has no type" << std::endl;
	return (_type);
}
