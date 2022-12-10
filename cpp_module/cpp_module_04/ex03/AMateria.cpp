#include <iostream>
#include "AMateria.hpp"

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
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICaracter &target)
{
	std::cout << "Define concrete Materia" << std::endl;
}