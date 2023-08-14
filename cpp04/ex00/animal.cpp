#include "animal.hpp"

// Canonical Form~
Animal::Animal() : type("Unknown")
{
	// std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal()
{
	// std::cout << "Animal destructor called" << std::endl;
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
// ~Canonical Form
std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal makes soundes" << std::endl;
}