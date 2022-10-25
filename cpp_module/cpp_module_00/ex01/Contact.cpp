#include <iostream>
#include "Contact.hpp"

bool	Contact::initFirstName(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Wrong First Name" << std::endl;
			return (false);
		}
	}
	this->firstName = str;
	return (true);
}

bool	Contact::initLastName(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Wrong Last Name" << std::endl;
			return (false);
		}
	}
	this->lastName = str;
}

void	Contact::initNickName(std::string str)
{
	this->nickName = str;
}

bool	Contact::initPhoneNumber(std::string str)
{
	if (str.size() != 13 || str[3] != '-' || str[8] != '-')
	{
		std::cout << "Wrong Phone number" << std::endl;
		return (false);
	}
	this->phoneNumber = str;
	return (true);
}

void	Contact::initDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}