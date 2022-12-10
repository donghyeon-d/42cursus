#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#define MAX_ITEM 4
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string _name;
		AMateria *_inventory[MAX_ITEM];
		int	_itemCount;

	public :
		Character();
		Character(std::string name);
		Character(Character const &character);
		~Character();
		Character &operator=(Character const &Character);
		std::string const &getName() const;
		int getItemCount() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
