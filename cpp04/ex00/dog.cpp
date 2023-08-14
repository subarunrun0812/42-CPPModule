#include "dog.hpp"


// Canonical Form~
Dog::Dog()
{
	this->type = "Dog";
}
Dog::~Dog()
{
}
Dog::Dog(const Dog& dog) : Animal(dog)
{
}

Dog& Dog::operator=(Dog& dog)
{
	Animal::operator=(dog);
	return *this;
}
// ~Canonical Form

void Dog::makeSound() const
{
	std::cout << "ワン！ワン！" << std::endl;
}
