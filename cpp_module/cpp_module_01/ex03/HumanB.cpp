#include "HumanB.hpp"

HumanB::HumanB( const std::string name )
{
	this->name = name;
	this->weapon.setType("no weapon");
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void )
{
	if (this->weapon.getType().compare("no weapon") == 0)
		std::cout << this->name << " can't attack. Has no weapon" << std::endl;	
	else
		std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}


void	HumanB::setWeapon( const Weapon &weapon )
{
	this->weapon = weapon;
}

std::string	HumanB::getWeapon( void )
{
	return (this->weapon.getType());
}