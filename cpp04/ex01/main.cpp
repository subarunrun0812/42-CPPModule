#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	//Animal objectsの配列を作成。DogとCatオブジェの半分ずつ
	Animal* (animal_array[4]);
	animal_array[0] = new Dog();
	animal_array[1] = new Dog();
	animal_array[2] = new Cat();
	animal_array[3] = new Cat();
	for (size_t i = 0; i < 4; i++)
	{
		delete animal_array[i];
	}

	std::cout << "=================================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	//TODO: メモリリークを確認する。



	return 0;

}