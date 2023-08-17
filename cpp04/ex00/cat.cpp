#include "cat.hpp"

// Canonical Form~

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy contructor called" << std::endl;
}
Cat& Cat::operator=(Cat& cat)
{
	Animal::operator=(cat);
	return *this;
}
// ~Canonical Form

void Cat::makeSound() const
{
	std::cout << "ニャオ！" << std::endl;
}