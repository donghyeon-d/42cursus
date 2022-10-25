#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->inputIndex = 0;
	this->cnt = 0;
}

PhoneBook::~PhoneBook(void)
{
	this->inputIndex = 0;
	this->cnt = 0;
}

void	PhoneBook::exitBook(void)
{
	std::cout << "GOOD BYE!! YOU LOST CONTACT FOREVER!!" << std::endl;
	exit(0);
}

void	PhoneBook::add(void)
{
	// enter contact field
	std::string text;
	Contact contact;
	std::cout << "Enter First Name : ";
	std::cin >> text;
	contact.initFirstName(text);
	std::cout << "Enter Last Name : ";
	std::cin >> text;
	contact.initLastName(text);
	std::cout << "Enter Nick Name : ";
	std::cin >> text;
	contact.initNickName(text);
	std::cout << "Enter PhoneNumber : ";
	std::cin >> text;
	contact.initPhoneNumber(text);
	std::cout << "Enter Secret memo : ";
	std::cin >> text;
	contact.initDarkestSecret(text);

	// contact to phone book
	if (contact.isEmptyField() == true)
		std::cout << "You must enter all field accurately. Try First" << std::endl;
	else
	{
		this->contact[this->inputIndex] = contact;
		if (this->cnt < 8)
			this->cnt++;
		this->inputIndex = (this->inputIndex + 1) % 8;
	}
}

void	PhoneBook::search(void)
{
	for (int i = 0; i < this->cnt; i++)
	{
		std::cout << "         " << i + 1 << "|";
		this->contact[i].printContactSearch();
		std::cout << std::endl;
	}
	std::cout << "Enter contact index : ";
	int index = -1;
	std::cin >> index;
	if (0 < index && index < this->cnt + 1)
		this->contact[index - 1].printContactIndex();
	else
		std::cout << "Wrong index! Try First" << std::endl;
}