#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "default constructor : Zombie has no name" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << "construct : " << name << std::endl;
}


Zombie::~Zombie()
{
	std::cout << this->name << " is destructed" << std::endl;
}

void	(Zombie::setName)( std::string name )
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
