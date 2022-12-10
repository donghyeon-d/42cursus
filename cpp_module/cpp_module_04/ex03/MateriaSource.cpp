#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _sourceListIndex(0);
{
	for (int i = 0; i < MAX_LEARN; i++)
		_sourceList[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource)
{

}

MateriaSource::~MateriaSource()
{

}

MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{

}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria MateriaSource::*createMateria(std::string const &type)
{

}
