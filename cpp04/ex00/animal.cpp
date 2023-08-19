#include "animal.hpp"

// Canonical Form~
Animal::Animal() : type("Animal")
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
	std::cout << "Animal\tcopu constructor called" << std::endl;
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
	std::cout << "Animal\tアニマル  アニマル" << std::endl;
}