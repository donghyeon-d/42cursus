#include "Weapon.hpp"

#ifndef IOSTREAM
# define IOSTREAM

#include <iostream>

#endif

#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB {

	private:
		std::string name;
		Weapon weapon;

	public:
		HumanB( const std::string name );
		~HumanB( void );
		void	attack( void );
		void	setWeapon( const Weapon &weapon );
		std::string	getWeapon( void );
};



#endif