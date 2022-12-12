#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria() : No type!!" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria(type) : " << type << std::endl;
}

AMateria::AMateria(AMateria const &aMateria)
{
	std::cout << "AMateria(copy) : " << std::endl;
	*this = aMateria;
}

AMateria::~AMateria()
{
	std::cout << "~AMateria()" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &aMateria)
{
	_type = aMateria.getType();
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Define concrete Materia. you can't use to " << target.getName() << std::endl;
}