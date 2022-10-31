#include "Zombie.hpp"

int main()
{
	Zombie zombie1("aaa");
	zombie1.announce();
	randomChump("bbb");
	Zombie *zombie2 = newZombie("ccc");
	zombie2->announce();
	delete zombie2;// delete안하면 distructer 실행이 안됨. 그래서 좀비인듯..?
	// system("leaks BraiiiiiiinnnzzzZ");
	return (0);
}