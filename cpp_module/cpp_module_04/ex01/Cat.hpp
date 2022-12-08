#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal
{
	private :
		Brain *_brain;

	public :
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat &operator=(const Cat &cat);
		void makeSound() const;
		std::string getType() const;
};

#endif
