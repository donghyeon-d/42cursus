#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap  { Constructor } called. No name" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap { Constructor } called. name is " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap { Copy constructor } called. name is " << _name << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap { Destructor } called. Name " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    _name = scavTrap.getName();
	_hitPoint = scavTrap.getHitPoint();
	_energyPoint = scavTrap.getEnergyPoint();
	_attackDamage = scavTrap.getAttackDamage();
    std::cout << "ScavTrap { Assignment operator } called. name is " << _name << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoint == 0)
		std::cout << "ScavTrap " << _name << " : Empty Energy, can't attack" << std::endl;
	else if (_hitPoint == 0)
		std::cout << "ScavTrap " << _name << " : Hit point is 0, can't attack" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " : attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " : Gate Keeper mode!" << std::endl;
}