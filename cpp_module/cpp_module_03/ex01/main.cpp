#include <iostream>
#include "ScavTrap.hpp"

int main()
{
    ScavTrap A("A");
    ScavTrap AA(A);
    ScavTrap B("B");
    ScavTrap BB;
    BB = B;

    A.attack("B");
    B.takeDamage(A.getAttackDamage());
    B.guardGate();
    B.beRepaired(10);
}