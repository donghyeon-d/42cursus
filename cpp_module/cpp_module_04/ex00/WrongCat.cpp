#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat()" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cat)
{
	std::cout << "WrongCat(copy)" << std::endl;
	*this = cat;
}

WrongCat::~WrongCat()
{
	std::cout << "~WrongCat()" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	_type = cat._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow !!" << std::endl;
}

std::string WrongCat::getType() const
{
	return (_type);
}
