#include "dog.hpp"

// Canonical Form~
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog\tconstructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog\tdestructor called" << std::endl;
}
Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog\tcopy contructor called" << std::endl;
}

Dog &Dog::operator=(Dog &dog)
{
	Animal::operator=(dog);
	return *this;
}
// ~Canonical Form

void Dog::makeSound() const
{
	std::cout << "ワン！ワン！" << std::endl;
}
