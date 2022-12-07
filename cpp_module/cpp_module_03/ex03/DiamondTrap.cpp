#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap { Constructor } called. No name" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "Frag"), ScavTrap(name + " Scav")
{
	_name = name;
	std::cout << "DiamondTrap { Constructor } called. name is " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << "DiamondTrap { Copy constructor } called. name is " << _name << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << std::endl;
	std::cout << "DiamondTrap { Destructor } called. Name " << _name << std::endl;
}


DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	_name = diamondTrap._name;
	_hitPoint = diamondTrap._hitPoint;
	_energyPoint = diamondTrap._energyPoint;
	_attackDamage = diamondTrap._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << getName() << std::endl;
	std::cout << ClapTrap::getName() << std::endl;
	std::cout << FragTrap::getName() << std::endl;
	std::cout << ScavTrap::getName() << std::endl;
}








std::string DiamondTrap::getName() const
{
	return (_name);
}

unsigned int DiamondTrap::getHitPoint() const
{
	return (_hitPoint);
}

unsigned int DiamondTrap::getEnergyPoint() const
{
	return (_energyPoint);
}

unsigned int DiamondTrap::getAttackDamage() const
{
	return (_attackDamage);
}