#include <iostream>
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() : _sourceListCount(0)
{
	std::cout << "MateriaSource()" << std::endl;
	for (int i = 0; i < MAX_LEARN; i++)
		_sourceList[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource) : _sourceListCount(0)
{
	std::cout << "MateriaSource(copy)" << std::endl;
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	std::cout << "~MateriaSource()" << std::endl;
	for (int i = 0; i < getSourceListCount(); i++)
		delete _sourceList[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{
	for (int i = 0; i < MAX_LEARN; i++)
	{
		if (_sourceList[i] != 0)
			delete _sourceList[i];
		_sourceList[i] = materiaSource._sourceList[i];
	}
	_sourceListCount = materiaSource.getSourceListCount();
	return (*this);
}

int MateriaSource::getSourceListCount() const
{
	return (_sourceListCount);
}

void MateriaSource::learnMateria(AMateria *newMateria)
{
	if (getSourceListCount() == 4)
	{
		std::cout << "Full learn materia list" << std::endl;
	}
	_sourceList[getSourceListCount()] = newMateria;
	_sourceListCount++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i(0);
	while (i < MAX_LEARN)
	{
		// std::cout << "!! " << _sourceList[i]->getType() << std::endl;
		if (_sourceList[i] == 0 || type == _sourceList[i]->getType())
			break ;
		i++;
	}
	if (_sourceList[i] == 0 || i == MAX_LEARN)
			return 0;
	AMateria *newMateria = _sourceList[i]->clone();
	return (newMateria);
}
