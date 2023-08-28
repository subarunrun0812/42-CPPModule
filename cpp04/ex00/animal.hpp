#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define GREEN \x1b32m
#define DEFAULT \x1b0m

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	// 仮想関数w
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
