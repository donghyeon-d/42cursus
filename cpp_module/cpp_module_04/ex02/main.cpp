#include "Brain.hpp"
#include "Animal.hpp"
#include "AAnimal.hpp"
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

	{
		Animal animal;
		AAnimal Aanimal;
		std::cout << Aanimal.makeSound() << std::endl;
	}

	// system("leaks a.out");
	return (0);
}