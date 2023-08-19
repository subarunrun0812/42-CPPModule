#include "WrongCat.hpp"

// Canonical Form~

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat\tconstructor called" << std::endl;

}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat\tdestructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& Wrongcat) : WrongAnimal(Wrongcat)
{
	std::cout << "WrongCat\tcopy constructor called" << std::endl;

}
WrongCat& WrongCat::operator=(const WrongCat& Wrongcat)
{
	WrongAnimal::operator=(Wrongcat);
	return *this;
}
// ~Canonical Form

void WrongCat::makeSound() const
{
	std::cout << "ロングキャット  ロングキャット" << std::endl;
}