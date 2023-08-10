#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Foo");
    zombie->announce();
	randomChump("Random");
    delete zombie;

}

// #include <stdlib.h>
// __attribute__((destructor)) static void destructor(void) {
// 	system("leaks -q ex00");
// }
