#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("pipe");
		Weapon	club1 = Weapon("chair");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("fork");
		bob.attack();
		bob.setWeapon(club1);
		bob.attack();
		club.setType("desk");
		bob.attack();
	}
	std::cout << "\n\n";
	{
		Weapon club = Weapon("pipe");
		Weapon	club1 = Weapon("chair");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(&club);
		jim.attack();
		club.setType("fork");
		jim.attack();
		jim.setWeapon(&club1);
		jim.attack();
		club1.setType("desk");
		jim.attack();
	}
	// system("leaks a.out");
}