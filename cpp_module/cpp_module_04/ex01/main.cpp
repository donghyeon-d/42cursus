#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		Animal *animal[4];

		for (int i = 0; i < 2; i++)
			animal[i] = new Dog();
		for (int i = 2; i < 4; i++)
			animal[i] = new Cat();

		for (int i = 0; i < 4; i++)
			delete animal[i];
	}

	{
		Cat A;
		std::string a ("My Name is Tom");
		A.addIdeaToBrain(a);
		a = "What's your Name?";
		A.addIdeaToBrain(a);
		A.printIdeasFromBrain();

		Cat B;
		B = A;
		B.printIdeasFromBrain();
	}

	// system("leaks a.out");
	return (0);
}