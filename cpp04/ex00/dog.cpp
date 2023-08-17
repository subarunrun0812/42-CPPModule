#include "dog.hpp"


// Canonical Form~
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Cat constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Cat destructor called" << std::endl;
}
Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Cat copy contructor called" << std::endl;
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
