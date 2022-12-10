#include <iostream>

#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
	private:
		std::string _ideas[100];
		int	_ideasCount;
		
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		Brain &operator=(const Brain &brain);
		std::string getIdeaAtIndex(int index) const;
		int		getIdeasCount() const;
		void	addIdea(std::string &idea);
		void	printIdeas() const;
};

#endif
