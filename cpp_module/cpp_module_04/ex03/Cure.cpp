#include <iostream>
#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure()" << std::endl;
	_type = "cure";
}

Cure::Cure(Cure &cure)
{
	std::cout << "Cure(copy)" << std::endl;
	_type = "cure";
}

Cure::~Cure()
{
	std::cout << "~Cure()" << std::endl;
}

Cure &Cure::operator=(Cure *cure)
{
	_type = cure->getType();
	return (*this);
}

void Cure::use(ICaracter &target)
{
	std::cout << "* Heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}
