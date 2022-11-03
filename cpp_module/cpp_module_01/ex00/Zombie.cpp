#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << this->name << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destructed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
