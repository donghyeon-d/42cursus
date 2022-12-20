#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal()" << std::endl;
}

AAnimal::AAnimal(const AAnimal &Aanimal)
{
	std::cout << "AAnimal(copy)" << std::endl;
	*this = Aanimal;
}

AAnimal::~AAnimal()
{
	std::cout << "~AAnimal()" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &Aanimal)
{
	_type = Aanimal._type;
	return (*this);
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "AAnimal instance can't make sound" << std::endl;
// }

std::string AAnimal::getType() const
{
	std::cout << "AAnimal has no type" << std::endl;
	return (_type);
}
