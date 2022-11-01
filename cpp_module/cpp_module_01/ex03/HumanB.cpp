#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void )
{
	std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
}


void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

std::string	HumanB::getWeapon( void )
{
	return (this->weapon->getType());
}