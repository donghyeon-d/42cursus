#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#define SCAV_HP 100
#define SCAV_EP 50
#define SCAV_AD 20

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &scavTrap);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &scavTrap);
        void    attack(const std::string& target);
        void    guardGate();
};

#endif
