#include "animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "Animal\tconstructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal\tdestructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->type = animal.type;
	// std::cout << "Animal Copy Constructor" << std::endl;
}
Animal &Animal::operator=(const Animal &animal)
{
	this->type = animal.type;
	return *this;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "アニマル アニマル" << std::endl;
}