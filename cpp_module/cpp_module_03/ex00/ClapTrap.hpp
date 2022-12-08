#include <iostream>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
	private:
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
		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;
};

#endif
