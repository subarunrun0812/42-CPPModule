#include "cat.hpp"

// Canonical Form~

Cat::Cat()
{
	this->type = "Cat";
}
Cat::~Cat()
{
}
Cat::Cat(const Cat& cat) : Animal(cat)
{
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