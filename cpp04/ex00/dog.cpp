#include "dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog construcotr called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "ワン！ワン！" << std::endl;
}
