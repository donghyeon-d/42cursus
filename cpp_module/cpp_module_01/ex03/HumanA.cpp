#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon *newWeapon )
{
	this->name = name;
	this->weapon = newWeapon;
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

std::string	HumanA::getWeapon( void )
{
	return (this->weapon->getType());
}