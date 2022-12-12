#include <iostream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"


Character::Character() : _itemCount(0)
{
	std::cout << "Character() : No Name" << std::endl;
	for (int i = 0; i < MAX_ITEM; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name), _itemCount(0)
{
	std::cout << "Character(name) : " << name << std::endl;
	for (int i = 0; i < MAX_ITEM; i++)
		_inventory[i] = 0;
}

Character::Character(Character const &character)
{
	std::cout << "Character(copy)" << std::endl;
	*this = character;
}

Character::~Character()
{
	std::cout << "~Character()" << std::endl;
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (_inventory[i] != 0)
			delete _inventory[i];
	}
}

Character &Character::operator=(Character const &character)
{
	_name = character.getName();
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (_inventory[i] != 0)
			delete _inventory[i];
		_inventory[i] = character._inventory[i]->clone();
	}
	_itemCount = character.getItemCount();
	return (*this);
}


std::string const &Character::getName() const
{
	return (_name);
}

int Character::getItemCount() const
{
	return (_itemCount);
}

void Character::equip(AMateria *m)
{
	if (getItemCount() == MAX_ITEM)
	{
		std::cout << "Full Inventory" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			break ;
		}
	}
	_itemCount++;
}

void Character::unequip(int idx)
{
	if (getItemCount() == 0)
	{
		std::cout << "Empty Inventory" << std::endl;
		return ;
	}
	_inventory[idx] = 0;
	_itemCount--;
}

void Character::use(int idx, ICharacter &target)
{
	if (getItemCount() == 0)
	{
		std::cout << "Empty Inventory" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
