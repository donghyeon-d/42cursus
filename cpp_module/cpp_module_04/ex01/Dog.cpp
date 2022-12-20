#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog()" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal()
{
	std::cout << "Dog(copy)" << std::endl;
	_brain = new Brain();
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "~Dog()" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog.getType();
	*_brain = *(dog._brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark !!" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}

void	Dog::addIdeaToBrain(std::string &idea)
{
	_brain->addIdea(idea);
}

void	Dog::printIdeasFromBrain() const
{
	_brain->printIdeas();
}

int		Dog::getIdeaCount() const
{
	return (_brain->getIdeasCount());
}

