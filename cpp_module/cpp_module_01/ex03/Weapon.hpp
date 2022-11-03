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
		Weapon( void );
		Weapon( const std::string type );
		~Weapon( void );
		std::string	getType( void );
		void		setType( const std::string newType );
};

#endif