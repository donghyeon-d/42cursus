#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->inputIndex = 0;
	this->cnt = 0;
}

void	PhoneBook::add(Contact contact)
{
	this->contact[inputIndex] = contact;
	if (this->cnt < 8)
		this->cnt++;
	if (this->cnt == 7)
		this->inputIndex = 0;
	else
		this->inputIndex++;
}

void	PhoneBook::search(void)
{
	
}