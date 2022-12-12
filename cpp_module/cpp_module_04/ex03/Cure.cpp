#include <iostream>
#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure()
{
	std::cout << "Cure()" << std::endl;
	_type = "cure";
}

Cure::Cure(Cure const &cure)
{
	std::cout << "Cure(copy)" << std::endl;
	*this = cure;
}

Cure::~Cure()
{
	std::cout << "~Cure()" << std::endl;
}

Cure &Cure::operator=(Cure const &cure)
{
	_type = cure.getType();
	return (*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* Heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure());
}
