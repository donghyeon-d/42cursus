#ifndef STRING
# define STRING

#include <string>

# endif

#ifndef CONTACT_CPP
# define CONTACT_CPP


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
		void	initNickName(std::string str);
		bool	initPhoneNumber(std::string str);
		void	initDarkestSecret(std::string str);
};

# endif