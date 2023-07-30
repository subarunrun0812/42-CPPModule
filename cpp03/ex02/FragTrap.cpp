#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name)\
 : ClapTrap(name,100,100,30)
{
	std::cout << "Constructor(FragTrap)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor(FragTrap)" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->name << " requests high fives" << std::endl;
}