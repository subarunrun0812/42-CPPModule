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
	Cat(const Cat &cat);
	Cat& operator=(Cat &cat);
	void makeSound() const;
};

#endif