#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie = zombieHorde(5, "test");
	for (size_t i = 0; i < 5; i++)
	{
		zombie[i].announce();
	}
	delete[] zombie;
}

// #include <stdlib.h>
// __attribute__((destructor)) static void destructor(void) {
// 	system("leaks -q ex01");
// }
