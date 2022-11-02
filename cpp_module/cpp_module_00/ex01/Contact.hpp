#ifndef STRING
# define STRING

#include <string>

# endif

#ifndef CONTACT_HPP
# define CONTACT_HPP


class Contact {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		bool	initFirstName(std::string str);
		bool	initLastName(std::string str);
		bool	initNickName(std::string str);
		bool	initPhoneNumber(std::string str);
		bool	initDarkestSecret(std::string str);
		bool	isEmptyField();
		void	printContactSearch();
		void	printContactIndex();
};

# endif