#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
	private :
		Brain *_brain;

	public :
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog &operator=(const Dog &dog);
		void makeSound() const;
		std::string getType() const;
		void	addIdeaToBrain(std::string &idea);
		void	printIdeasFromBrain() const;
		int		getIdeaCount() const;
};

#endif
