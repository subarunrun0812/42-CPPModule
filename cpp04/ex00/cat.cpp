#include "Cat.hpp"

// Canonical Form~

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat\tconstructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat\tdestructor called" << std::endl;
}
Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat\tcopy contructor called" << std::endl;
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