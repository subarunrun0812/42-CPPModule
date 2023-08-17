#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = "I AM VERY SMART!!!";
	}

	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::string* other_ideas = other.getIdeas();
	this->ideas = new std::string[100];
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = other_ideas[i];
	}
}

Brain& Brain::operator=(const Brain& brain)
{
	// std::cout << "brain.ideas = " << brain.ideas->length() << std::endl;
	for (size_t i = 0; i < brain.ideas->length(); i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

std::string* Brain::getIdeas() const
{
	return (this->ideas);
}