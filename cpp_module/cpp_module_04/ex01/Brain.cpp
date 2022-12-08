#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain()" << std::endl;
}

Brain::Brain(const Brain &brain)
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
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain.getIdeaAtIndex(i);
	return (*this);
}

std::string Brain::getIdeaAtIndex(int index) const
{
	return (_ideas[index]);
}
