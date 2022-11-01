#include "Zombie.hpp"

int main()
{
	int N (10);
	Zombie *zombies = zombieHorde(N, "zozommbibi");
	for (int i = 0; i < N; i++)
	{
		std::cout << "zombies[" << i << "] : ";
		zombies[i].announce();
	}
	delete[] zombies;
	// system("leaks zombieHorde");
	return (0);
}