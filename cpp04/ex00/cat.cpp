#include "cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat construcotr called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "ニャオ！" << std::endl;
}