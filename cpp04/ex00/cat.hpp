#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	~Cat();
	void makeSound() const;
};

#endif