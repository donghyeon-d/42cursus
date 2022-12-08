#include <iostream>
#include "FragTrap.hpp"

int main()
{
    FragTrap A("A");
    FragTrap AA(A);
    FragTrap B("B");
    FragTrap BB;
    BB = B;

    A.attack("B");
    B.takeDamage(A.getAttackDamage());
    B.highFivesGuys();
    B.beRepaired(10);

    std::cout << "A Name  : " << A.getName() << " | AD : " << A.getAttackDamage() << " | EP :  " << A.getEnergyPoint() << " | HP " << A.getHitPoint()  << std::endl;
    std::cout << "AA Name : " << AA.getName() << " | AD : " << AA.getAttackDamage() << " | EP :  " << AA.getEnergyPoint() << " | HP " << AA.getHitPoint()  << std::endl;
    std::cout << "B Name  : " << B.getName() << " | AD : " << B.getAttackDamage() << " | EP :  " << B.getEnergyPoint() << " | HP " << B.getHitPoint()  << std::endl;
    std::cout << "BB Name : " << BB.getName() << " | AD : " << BB.getAttackDamage() << " | EP :  " << BB.getEnergyPoint() << " | HP " << BB.getHitPoint()  << std::endl;
}
