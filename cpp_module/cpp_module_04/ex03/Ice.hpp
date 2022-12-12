#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice const &ice);
		~Ice();
		Ice &operator=(Ice const &ice);
		void use(ICharacter &target);
		AMateria *clone() const;
};


#endif
