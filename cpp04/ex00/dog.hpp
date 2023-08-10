#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	~Dog();
	void makeSound() const;
};

#endif