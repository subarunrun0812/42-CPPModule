#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <sstream>

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;
	return 0;
}