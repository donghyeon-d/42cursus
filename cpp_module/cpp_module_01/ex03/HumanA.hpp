#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {

	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA( const std::string name, Weapon &newWeapon );
		~HumanA( void );
		void	attack( void );
		void	setWeaponTest( Weapon newWeapon );
		const std::string	&getWeapon( void );
};

#endif