#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	// TODO:WrongAnimalクラスを継承したWrongCatクラスを実装する。

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << std::endl;

	std::cout << i->getType() << ": ";
	i->makeSound(); // will output the cat sound!
	std::cout << std::endl;
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}