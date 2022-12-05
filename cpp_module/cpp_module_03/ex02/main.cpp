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
    B.takeDamage(30);
    B.highFivesGuys();
    B.beRepaired(10);
}