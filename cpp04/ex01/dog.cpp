#include "dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog construcotr called" << std::endl;
}

//コピーコンストラクタ
Dog::Dog(const Dog& other)
{
	type = other.type;
	this->brain = new Brain(*(other.brain));
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog& dog)
{
	this->type = dog.type;
	if (this->brain)
		delete brain;
	this->brain = new Brain(*(dog.brain));
	Animal::operator=(dog);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "ワン！ワン！" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}