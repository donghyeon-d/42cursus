#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#define MAX_LEARN 4
#include "IMateriaSource.hpp"


class MateriaSource
{
	private :
		AMateria *_sourceList[MAX_LEARN];
		int _sourceListIndex;

	public :
		MateriaSource();
		MateriaSource(MateriaSource const &materiaSource);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &materiaSource);
		void learnMateria(AMateria*);
		AMateria *createMateria(std::string const &type);
};

#endif