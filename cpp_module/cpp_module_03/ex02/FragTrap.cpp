#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap  { Constructor } called. No name" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap  { Constructor } called. name is " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	std::cout << "FragTrap { Copy constructor } called. name is " << _name << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap { Destructor } called. Name " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    _name = fragTrap.getName();
	_hitPoint = fragTrap.getHitPoint();
	_energyPoint = fragTrap.getEnergyPoint();
	_attackDamage = fragTrap.getAttackDamage();
    std::cout << "FragTrap { Assignment operator } called. name is " << _name << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Positive hige fives!!" << std::endl;
}
