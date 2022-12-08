#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#define FRAG_HP 100
#define FRAG_EP 100
#define FRAG_AD 30

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
};

#endif
