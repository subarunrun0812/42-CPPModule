#include "cat.hpp"

// brainポインタに新しいBrainオブジェクトが割り当てられる。
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat\tconstrucotr called" << std::endl;
}

//コピーコンストラクタ
Cat::Cat(const Cat& other)
{
	this->type = other.type;
	this->brain = new Brain(*(other.brain));
	std::cout << "Cat\tcopy constructor" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat\tdestructor called" << std::endl;
}

Cat& Cat::operator=(Cat& cat)
{
	this->type = cat.type;
	if (this->brain)
		delete brain;
	this->brain = new Brain(*(cat.brain));
	Animal::operator=(cat);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "ニャオ！" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}