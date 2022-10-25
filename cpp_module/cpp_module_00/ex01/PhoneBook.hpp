#include "Contact.hpp"

#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

class PhoneBook {

	private:
		Contact	contact[8];
		int		inputIndex;
		int		cnt;
	
	public:
		PhoneBook( void );
		void	add(Contact contact);
		void	search(void);
};

# endif