#include <iostream>

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

class AAnimal
{
	protected :
		std::string _type;
	
	public :
		AAnimal();
		AAnimal(const AAnimal &animal);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &animal);
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
};

#endif
