#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("pipe");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("fork");
		bob.attack();
	}
	{
		Weapon club = Weapon("pipe");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("fork");
		jim.attack();
	}
	// system("leaks a.out");
}