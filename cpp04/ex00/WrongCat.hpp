#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& WrongCat);
	WrongCat& operator=(const WrongCat& WrongCat);
	// 仮想関数
	virtual ~WrongCat();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif