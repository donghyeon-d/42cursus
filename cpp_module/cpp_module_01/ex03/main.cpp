#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club("crude spiked club");
		// Weapon	weapon = Weapon("fork");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		// bob.setWeaponTest(weapon);
		// bob.attack();
		// weapon.setType("pipe");
		// bob.attack();
		// std::cout << "club.getType() : " << club.getType() << std::endl;
		// std::cout << "weapon.getType() : " << weapon.getType() << std::endl;
	}
	std::cout << "\n";
	{
		Weapon club ("crude spiked club");
		// Weapon	weapon = Weapon("fork");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		// jim.setWeapon(weapon);
		// jim.attack();
		// weapon.setType("pipe");
		// jim.attack();
	}
	// system("leaks a.out");
}