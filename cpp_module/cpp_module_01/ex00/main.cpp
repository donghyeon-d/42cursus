#include "Zombie.hpp"

int main()
{
	Zombie zombie1("aaa");
	zombie1.announce();
	randomChump("bbb");
	Zombie *zombie2 = newZombie("ccc");
	zombie2->announce();
	delete zombie2;
	// system("leaks BraiiiiiiinnnzzzZ");
	return (0);
}