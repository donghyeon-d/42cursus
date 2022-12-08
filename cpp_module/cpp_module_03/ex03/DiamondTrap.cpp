#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap { Constructor } called. No name" << std::endl;
	_hitPoint = FRAG_HP;
	_energyPoint = SCAV_EP;
	_attackDamage = FRAG_AD;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoint = FRAG_HP;
	_energyPoint = SCAV_EP;
	_attackDamage = FRAG_AD;
	std::cout << "DiamondTrap { Constructor } called. name is " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << "DiamondTrap { Copy constructor } called. name is " << _name << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap { Destructor } called. Name " << _name << std::endl;
}


DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	_name = diamondTrap.getName();
	_hitPoint = diamondTrap.getHitPoint();
	_energyPoint = diamondTrap.getEnergyPoint();
	_attackDamage = diamondTrap.getAttackDamage();
	std::cout << "DiamondTrap { operator } called. name is " << _name << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Name : " << getName() << std::endl;
	std::cout << "ClapTrap Name    : " << ClapTrap::getName() << std::endl;
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

void	DiamondTrap::printInfo() const
{
	std::cout << "Name : " << getName() << std::endl;
	std::cout << "HP   : " << getHitPoint() << std::endl;
	std::cout << "EP   : " << getEnergyPoint() << std::endl;
	std::cout << "AD   : " << getAttackDamage() << std::endl;
}