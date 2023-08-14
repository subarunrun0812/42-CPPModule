#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const std::string name);
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap &flagTrap);
	FragTrap &operator=(const FragTrap &flagTrap);
	void highFivesGuys(void);
};

#endif