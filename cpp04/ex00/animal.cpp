#include "animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal makes soundes" << std::endl;
}