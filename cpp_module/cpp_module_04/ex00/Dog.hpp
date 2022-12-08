#include <iostream>
#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog &operator=(const Dog &dog);
		void makeSound() const;
		std::string getType() const;
};

#endif
