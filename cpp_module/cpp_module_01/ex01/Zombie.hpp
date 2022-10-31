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
		Zombie( std::string name );
		~Zombie( void );
		void announce( void );
};

#endif