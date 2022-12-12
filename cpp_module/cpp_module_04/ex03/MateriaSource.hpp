#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#define MAX_LEARN 4
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_sourceList[MAX_LEARN];
		int _sourceListCount;

	public :
		MateriaSource();
		MateriaSource(MateriaSource const &materiaSource);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &materiaSource);
		void learnMateria(AMateria *newMateria);
		AMateria *createMateria(std::string const &type);
		int getSourceListCount() const;
};

#endif