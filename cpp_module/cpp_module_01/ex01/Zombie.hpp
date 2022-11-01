#ifndef IOSTREAM
# define IOSTREAM

#include <iostream>

#endif


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:
		std::string name;
	
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie( void );
		void setName( std::string name );
		void announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif