#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &cure);
		~Cure();
		Cure &operator=(Cure const &cure);
		void use(ICharacter &target);
		AMateria *clone() const;
};


#endif
