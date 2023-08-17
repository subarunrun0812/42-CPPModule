#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound(); // will output the cat sound!
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		const WrongAnimal* j = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << ": ";
		i->makeSound(); // will output the cat sound!
		std::cout << j->getType() << ": ";
		j->makeSound();
		delete j;
		delete i;
	}
	return 0;
}