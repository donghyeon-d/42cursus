#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap  { Constructor } called. No name" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap { Constructor } called. name is " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	*this = clapTrap;
	std::cout << "ClapTrap { Copy constructor } called. name is " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap { Destructor } called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	_name = clapTrap._name;
	_hitPoint = clapTrap._hitPoint;
	_energyPoint = clapTrap._energyPoint;
	_attackDamage = clapTrap._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoint == 0)
		std::cout << "ClapTrap " << _name << " : Empty Energy, can't attack" << std::endl;
	else if (_hitPoint == 0)
		std::cout << "ClapTrap " << _name << " : Hit point is 0, can't attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " : attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " : already Died" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " : take damege " << amount << " HP" << std::endl;
		if (_hitPoint <= amount)
		{
			std::cout << "ClapTrap " << _name << " is killed" << std::endl;
			_hitPoint = 0;
		}
		else
		{
			_hitPoint -= amount;
			std::cout << "ClapTrap " << _name << " HP : " << _hitPoint << std::endl;
		}
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint == 0)
		std::cout << "ClapTrap " << _name << " : Empty Energy, can't repair" << std::endl;
	else if (_hitPoint <= 0)
		std::cout << "ClapTrap " << _name << " : already died, can't repair" << std::endl;
	else
	{
		_hitPoint += amount;
		std::cout << "ClapTrap " << _name << " : is repaired " << amount << " HP, HP : " << _hitPoint << std::endl;
		_energyPoint--;
	}
}

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoint()  const
{
	return (_hitPoint);
}

unsigned int ClapTrap::getEnergyPoint()  const
{
	return (_energyPoint);
}

unsigned int ClapTrap::getAttackDamage()  const
{
	return (_attackDamage);
}
