#ifndef IOSTREAM
# define IOSTREAM

#include <iostream>

#endif

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {

	private:
		std::string type;
	
	public:
		Weapon( std::string type );
		~Weapon( void );
		std::string	getType( void );
		void		setType( std::string newType );
};

#endif