#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}