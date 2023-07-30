#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
	 : ClapTrap(name,100,50,20)
{
	std::cout << "Constructor(ScavTrap)" << std::endl;

};
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor(ScavTrap)" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " <<
		target << ", causing " << this->attackDamage << " points of damage!"
		<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}