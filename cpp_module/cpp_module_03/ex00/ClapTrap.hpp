#include <iostream>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#define CLAPTRAP_MAX_HP 10

class ClapTrap
{
	private:
		std::string _name; // argument
		unsigned int _hitPoint; // 10
		unsigned int _energyPoint; // 10
		unsigned int _AttackDamage; // 0

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clapTrap);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif