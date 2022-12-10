#include "Brain.hpp"

Brain::Brain() : _ideasCount(0)
{
	std::cout << "Brain()" << std::endl;
}

Brain::Brain(const Brain &brain) : _ideasCount(0)
{
	std::cout << "Brain(copy)" << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "~Brain()" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain = " << std::endl;
	for (int i = 0; i < brain.getIdeasCount(); i++)
		_ideas[i] = brain.getIdeaAtIndex(i);
	_ideasCount = brain.getIdeasCount();
	return (*this);
}

std::string Brain::getIdeaAtIndex(int index) const
{
	if (index >= _ideasCount)
		std::cout << "it has just " << _ideasCount << "ideas" << std::endl;
	return (_ideas[index]);
}

int	Brain::getIdeasCount() const
{
	return (_ideasCount);
}

void	Brain::addIdea(std::string &idea)
{
	_ideas[getIdeasCount()] = idea;
	_ideasCount++;
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < getIdeasCount(); i++)
		std::cout << "[" << i << "] " << _ideas[i] << std::endl;
}
