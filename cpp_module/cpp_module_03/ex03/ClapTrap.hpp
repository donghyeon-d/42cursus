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
		virtual std::string getName() const;
		virtual unsigned int getHitPoint() const;
		virtual unsigned int getEnergyPoint() const;
		virtual unsigned int getAttackDamage() const;
};


#endif