#include <iostream>
#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice()" << std::endl;
	_type = "ice";
}

Ice::Ice(Ice &ice)
{
	std::cout << "Ice(copy)" << std::endl;
	_type = "ice";
}

Ice::~Ice()
{
	std::cout << "~Ice()" << std::endl;
}

Ice &Ice::operator=(Ice *ice)
{
	_type = ice->getType();
	return (*this);
}

void Ice::use(ICaracter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}
