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

static void	init_cin(void)
{
	std::cin.ignore();
	std::cin.clear();
	std::clearerr(stdin);
	std::cout << std::endl;
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
	Contact newContact;

	std::cout << "Enter First Name : ";
	if (!(std::getline(std::cin, text)))
		init_cin();
	else
		newContact.initFirstName(text);

	std::cout << "Enter Last Name : ";
	if (!(std::getline(std::cin, text)))
		init_cin();
	else
		newContact.initLastName(text);

	std::cout << "Enter Nick Name : ";
	if (!(std::getline(std::cin, text)))
		init_cin();
	else
		newContact.initNickName(text);

	std::cout << "Enter PhoneNumber : ";
	if (!(std::getline(std::cin, text)))
		init_cin();
	else
		newContact.initPhoneNumber(text);

	std::cout << "Enter Secret memo : ";
	if (!(std::getline(std::cin, text)))
		init_cin();
	else
		newContact.initDarkestSecret(text);

	// newContact to phone book
	if (newContact.isEmptyField() == true)
		std::cout << "You must enter all field accurately. Try First" << std::endl;
	else
	{
		this->contact[this->inputIndex] = newContact;
		if (this->cnt < 8)
			this->cnt++;
		this->inputIndex = (this->inputIndex + 1) % 8;
	}
}

void	PhoneBook::search(void)
{
	if (this->cnt == 0)
	{
		std::cout << "Empty phone book" << std::endl;
		return ;
	}

	// print phonebook list
	for (int i = 0; i < this->cnt; i++)
	{
		std::cout << "         " << i + 1 << "|";
		this->contact[i].printContactSearch();
		std::cout << std::endl;
	}

	// input index number
	std::cout << "Enter contact index : ";
	std::string indexBuffer;
	std::getline(std::cin, indexBuffer);
	if (std::cin.eof())
	{
		std::cout << "Wrong index! Try First" << std::endl;
		std::cin.clear();
		std::clearerr(stdin);
		return ;
	}
	std::size_t inputLen;
	int	index(-1);
	try
	{
		index = std::stoi(indexBuffer, &inputLen, 10);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Wrong index! Try First" << std::endl;
		return ;
	}
	catch(std::out_of_range)
	{
		std::cout << "Wrong index! Try First" << std::endl;
		return ;
	}
	// print contact[index]
	if (inputLen > 1)
		std::cout << "Wrong index! Try First" << std::endl;
	else if (0 < index && index < this->cnt + 1)
		this->contact[index - 1].printContactIndex();
	else
		std::cout << "Wrong index! Try First" << std::endl;
}
