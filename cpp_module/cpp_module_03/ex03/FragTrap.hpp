#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public :
		FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &fragTrap);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &fragTrap);
		void highFivesGuys(void);

        std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;
};


#endif