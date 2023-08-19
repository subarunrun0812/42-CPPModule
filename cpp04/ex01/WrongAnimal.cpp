#include "WrongAnimal.hpp"

// Canonical Form~
WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout << "WrongAnimal\tconstructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal\tdestructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	this->type = wronganimal.type;
	std::cout << "WrongAnimal\tCopy Constructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	this->type = wronganimal.type;
	return *this;
}
// ~Canonical Form
std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "ロングアニマル  ロングアニマル" << std::endl;
}