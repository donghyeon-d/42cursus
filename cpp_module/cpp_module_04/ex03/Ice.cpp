#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice()" << std::endl;
	_type = "ice";
}

Ice::Ice(Ice const &ice)
{
	std::cout << "Ice(copy)" << std::endl;
	*this = ice;
}

Ice::~Ice()
{
	std::cout << "~Ice()" << std::endl;
}

Ice &Ice::operator=(Ice const &ice)
{
	_type = ice.getType();
	return (*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	return (new Ice());
}
