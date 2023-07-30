#include "cat.hpp"

// brainポインタに新しいBrainオブジェクトが割り当てられる。
Cat::Cat() : brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat construcotr called" << std::endl;
}

//コピーコンストラクタ
Cat::Cat(const Cat& other) : brain(new Brain(*other.brain))
{
	type = other.type;
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "ニャオ！" << std::endl;
}