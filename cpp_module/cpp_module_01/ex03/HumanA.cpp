#include "HumanA.hpp"

HumanA::HumanA( const std::string name, Weapon &newWeapon ) : weapon(newWeapon)
{
	this->name = name;
	this->weapon = newWeapon;
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeaponTest( Weapon newWeapon )
{
	this->weapon = newWeapon;
}

std::string	HumanA::getWeapon( void )
{
	return (this->weapon.getType());
}