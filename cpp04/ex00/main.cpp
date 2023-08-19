#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << std::endl;
		std::cout << meta->getType() << ": ";
		meta->makeSound();
		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound(); // will output the cat sound!
		std::cout << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl
			  << "========================" << std::endl
			  << std::endl;
	{
		const WrongAnimal *i = new WrongAnimal();
		const WrongAnimal *j = new WrongCat();
		const WrongCat *k = new WrongCat();
		std::cout << std::endl;

		std::cout << i->getType() << ": ";
		i->makeSound(); // will output the cat sound!
		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << k->getType() << ": ";
		k->makeSound();
		std::cout << std::endl;
		delete j;
		// std::cout << "i をdeleteするよ" << std::endl;
		delete i;
		// std::cout << "k をdeleteするよ" << std::endl;
		delete k;
	}
	return 0;
}