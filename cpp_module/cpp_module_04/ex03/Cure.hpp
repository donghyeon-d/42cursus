#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class ICaracter;

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(Cure &cure);
		~Cure();
		Cure &operator=(Cure *cure);
		void use(ICaracter &target);
		AMateria *clone() const;
};


#endif
