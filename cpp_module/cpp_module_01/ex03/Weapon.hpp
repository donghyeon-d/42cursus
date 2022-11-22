#include <iostream>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {

	private:
		std::string type;

	public:
		Weapon( void );
		Weapon( const std::string type );
		~Weapon( void );
		const std::string	&getType( void );
		void		setType( std::string newType );
};

#endif