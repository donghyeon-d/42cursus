#include <iostream>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
	protected:
		std::string _name; // argument
		unsigned int _hitPoint; // 10
		unsigned int _energyPoint; // 10
		unsigned int _attackDamage; // 0

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clapTrap);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName();
		unsigned int getHitPoint();
		unsigned int getEnergyPoint();
		unsigned int getAttackDamage();
};


#endif