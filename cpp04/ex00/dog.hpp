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
	Dog(const Dog &dog);
	Dog& operator=(Dog &dog);
	void makeSound() const;
};

#endif