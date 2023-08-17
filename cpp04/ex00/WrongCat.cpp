#include "WrongCat.hpp"

// Canonical Form~

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}
WrongCat::~WrongCat()
{
}
WrongCat::WrongCat(const WrongCat& Wrongcat) : WrongAnimal(Wrongcat)
{
}
WrongCat& WrongCat::operator=(const WrongCat& Wrongcat)
{
	WrongAnimal::operator=(Wrongcat);
	return *this;
}
// ~Canonical Form

void WrongCat::makeSound() const
{
	std::cout << "WrongCat WrongCat WrongCat " << std::endl;
}