#include <iostream>
#include "Contact.hpp"

bool	Contact::initFirstName(std::string str)
{
	if (str.empty())
		return (false);
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Wrong First Name. only alphabet" << std::endl;
			return (false);
		}
	}
	this->firstName = str;
	return (true);
}

bool	Contact::initLastName(std::string str)
{
	if (str.empty())
		return (false);
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			std::cout << "Wrong Last Name. only alphabet" << std::endl;
			return (false);
		}
	}
	this->lastName = str;
	return (true);
}

bool	Contact::initNickName(std::string str)
{
	if (str.empty())
		return (false);
	this->nickName = str;
	return (true);
}

bool	Contact::initPhoneNumber(std::string str)
{
	if (str.empty())
		return (false);
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (!isnumber(str[i]) && str[i] != '-')
		{
			std::cout << "Wrong Phone number. only number or '-'" << std::endl;
			return (false);
		}
	}
	this->phoneNumber = str;
	return (true);
}

bool	Contact::initDarkestSecret(std::string str)
{
	if (str.empty())
		return (false);
	this->darkestSecret = str;
	return (true);
}

bool	Contact::isEmptyField(void)
{
	if (this->firstName.empty() || \
		this->lastName.empty() || \
		this->nickName.empty() || \
		this->phoneNumber.empty() || \
		this->darkestSecret.empty())
		return (true);
	else
		return (false);
};

static void	printStringSubstr(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		for (unsigned long i = 0; i < 10 - str.size(); i++)
			std::cout << " ";
		std::cout << str;
	}
}

void	Contact::printContactSearch(void)
{
	printStringSubstr(this->firstName);
	std::cout << "|";
	printStringSubstr(this->lastName);
	std::cout << "|";
	printStringSubstr(this->nickName);
}

void	Contact::printContactIndex(void)
{
	std::cout << "First name : " << this->firstName << std::endl;
	std::cout << "Last name  : " << this->lastName << std::endl;
	std::cout << "Nick name  : " << this->nickName << std::endl;
	std::cout << "Phone Num  : " << this->phoneNumber << std::endl;
	std::cout << "DarkSecret : " << this->darkestSecret << std::endl;
}