#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

int main()
{
	std::cout << "~~~ Catの頭脳の中を見てみるよ💓 ~~~" << std::endl;
	{
		const Cat cat;
		Brain *brain = cat.getBrain();
		std::string *str = brain->getIdeas();
		std::cout << "cat.brain = " << str[0] << std::endl;
	}
	std::cout << "~~~ Dogの頭脳の中を見てみるよ💓 ~~~" << std::endl;
	{
		const Dog dog;
		Brain *brain = dog.getBrain();
		std::string *str = brain->getIdeas();
		std::cout << "dog.brain = " << str[0] << std::endl;
	}

	std::cout << std::endl
			  << "========================" << std::endl
			  << std::endl;

	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j;
		delete i;
	}
	std::cout << std::endl
			  << "========================" << std::endl
			  << std::endl;
	{
		// Animal objectsの配列を作成。DogとCatオブジェの半分ずつ
		Animal *(animal_array[4]);
		animal_array[0] = new Dog();
		animal_array[1] = new Dog();
		animal_array[2] = new Cat();
		animal_array[3] = new Cat();
		for (size_t i = 0; i < 4; i++)
		{
			delete animal_array[i];
		}
	}

	return 0;
}

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q ex01");
// }