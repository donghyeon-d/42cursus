#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class ICaracter;

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(Ice &ice);
		~Ice();
		Ice &operator=(Ice *ice);
		void use(ICaracter &target);
		AMateria *clone() const;
};


#endif
