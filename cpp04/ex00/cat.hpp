#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(Cat &cat);
	void makeSound() const;
};

#endif