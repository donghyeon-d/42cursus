#include <iostream>

#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
	private:
		std::string _ideas[100];
		
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		Brain &operator=(const Brain &brain);
		std::string getIdeaAtIndex(int index) const;
};

#endif
