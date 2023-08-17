#include "dog.hpp"

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog construcotr called" << std::endl;
}

// コピーコンストラクタ
Dog::Dog(const Dog &other) : brain(new Brain(*other.brain))
{
	type = other.type;
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "ワン！ワン！" << std::endl;
}

Dog &Dog::operator=(Dog &dog)
{
	Animal::operator=(dog);
	return *this;
}
