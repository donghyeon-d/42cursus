#include "ClapTrap.hpp"

int main()
{
	ClapTrap tom("Tom");
	ClapTrap denise("Denise");
	ClapTrap tom_copy(tom);

	tom.attack("Denise");
	denise.takeDamage(5);
	denise.takeDamage(5);
	denise.beRepaired(5);
	
	ClapTrap paul("Paul");

	for (int i = 0; i < 11; i++)
	{ 
		std::cout << "attack count [" << i << "] : ";
		paul.attack("air");
	}
	paul.beRepaired(5);
}
