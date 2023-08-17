#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &brain)
{
	// std::cout << "brain.ideas = " << brain.ideas->length() << std::endl;
	for (size_t i = 0; i < brain.ideas->length(); i++)
	{
		this->ideas[i] = brain.ideas[i];
	}

	return *this;
}
