#include <iostream>
#include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(const WrongCat &cat);
		~WrongCat();
		WrongCat &operator=(const WrongCat &cat);
		void makeSound() const;
		std::string getType() const;
};

#endif
