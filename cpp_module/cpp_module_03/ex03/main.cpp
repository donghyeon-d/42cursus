#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap A("A");
    DiamondTrap B;
    B = DiamondTrap("B");
    std::cout << A.getName() << std::endl;
    std::cout << B.getName() << std::endl;

    A.whoAmI();
    A.printInfo();

    A.attack(B.getName());
    B.takeDamage(A.getAttackDamage());
}
