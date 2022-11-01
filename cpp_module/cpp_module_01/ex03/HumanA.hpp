
#include "Weapon.hpp"


#ifndef IOSTREAM
# define IOSTREAM

#include <iostream>

#endif

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {

	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanA( std::string name, Weapon *weapon );
		~HumanA( void );
		void attack( void );
		void	setWeapon(Weapon *weapon);
		std::string	getWeapon(void);
};

#endif