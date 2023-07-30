#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : private ClapTrap
{
	public:
		FragTrap(const std::string name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif