#include <iostream>

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
	protected :
		std::string _type;
	
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &animal);
		void makeSound() const;
		std::string getType() const;
};

#endif
