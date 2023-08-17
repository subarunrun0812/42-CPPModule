#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string name);
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap& operator =(const ScavTrap &scavTrap);
		void guardGate();
		//TODO: ScavTrapの方でattack()を新たに定義する
};

#endif