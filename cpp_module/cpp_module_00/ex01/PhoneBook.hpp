#include "Contact.hpp"

#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

class PhoneBook {

	private:
		Contact	contact[8];
		int		inputIndex;
		int		cnt;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	exitBook(void);
};

# endif