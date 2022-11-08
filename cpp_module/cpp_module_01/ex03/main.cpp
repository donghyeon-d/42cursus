#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("pipe");
		// Weapon	weapon = Weapon("chair");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("fork");
		bob.attack();
		// bob.setWeaponTest(weapon);
		// bob.attack();
		// weapon.setType("desk");
		// bob.attack();
		// std::cout << "club.getType() : " << club.getType() << std::endl;
		// std::cout << "weapon.getType() : " << weapon.getType() << std::endl;
	}
	std::cout << "\n";
	{
		Weapon club = Weapon("pipe");
		// Weapon	weapon = Weapon("chair");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("fork");
		jim.attack();
		// jim.setWeapon(weapon);
		// jim.attack();
		// weapon.setType("desk");
		// jim.attack();
	}
	// system("leaks a.out");
}