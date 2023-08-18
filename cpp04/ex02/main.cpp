#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <stdlib.h>

int main()
{
	std::cout << "=================================" << std::endl;
	{
		// Animalクラスは抽象クラスなので、宣言する事ができない。
		// Animal* animal = new Animal();
		// Animal animal;
		Dog* dog_memory = new Dog();
		Dog	dog_only;
		delete dog_memory;
	}
	// std::cout << "=================================" << std::endl;
	// {
	// 	//Animal objectsの配列を作成。DogとCatオブジェの半分ずつ
	// 	Animal* (animal_array[4]);
	// 	animal_array[0] = new Dog();
	// 	animal_array[1] = new Dog();
	// 	animal_array[2] = new Cat();
	// 	animal_array[3] = new Cat();
	// 	for (size_t i = 0; i < 4; i++)
	// 	{
	// 		delete animal_array[i];
	// 	}
	// }

	return 0;

}

__attribute__((destructor)) static void destructor(void) {
	system("leaks -q ex02");
}