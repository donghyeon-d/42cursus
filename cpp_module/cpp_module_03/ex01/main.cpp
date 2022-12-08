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
    std::cout << "Name : " << A.getName() << " | AD : " << A.getAttackDamage() << " | EP :  " << A.getEnergyPoint() << " | HP " << A.getHitPoint()  << std::endl;
    std::cout << "Name : " << AA.getName() << " | AD : " << AA.getAttackDamage() << " | EP :  " << AA.getEnergyPoint() << " | HP " << AA.getHitPoint()  << std::endl;
    std::cout << "Name : " << B.getName() << " | AD : " << B.getAttackDamage() << " | EP :  " << B.getEnergyPoint() << " | HP " << B.getHitPoint()  << std::endl;
    std::cout << "Name : " << BB.getName() << " | AD : " << BB.getAttackDamage() << " | EP :  " << BB.getEnergyPoint() << " | HP " << BB.getHitPoint()  << std::endl;
}
