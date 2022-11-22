#include "HumanB.hpp"

HumanB::HumanB( const std::string name ) : weapon(0)
{
	this->name = name;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void )
{
	if (this->weapon == 0)
		std::cout << this->name << " can't attack. Has no weapon" << std::endl;	
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}

const std::string	&HumanB::getWeapon( void )
{
	return (this->weapon->getType());
}