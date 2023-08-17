#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain &operator=(const Brain &brain);
};

#endif
