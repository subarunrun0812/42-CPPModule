#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
{
	this->name = name;
	std::cout << "\x1b[32mConstructors with arguments\x1b[0m" << std::endl;
}

ClapTrap::ClapTrap(const std::string name,int hitPoints,\
					int energyPoints, int attackDamage)
{
	this->name = name;
	this->hitPoints = hitPoints;
	this->energyPoints = energyPoints;
	this->attackDamage = attackDamage;
	std::cout << "\x1b[32mConstructors with arguments\x1b[0m" << std::endl;
}

// Canonical Form〜
ClapTrap::ClapTrap()
{
	std::cout << "\x1b[32mDefault Constructor\x1b[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\x1b[32mDestructor\x1b[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	std::cout << "\x1b[32mCopy Constructor\x1b[0m" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return *this;
}
// 〜Canonical Form

int ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "\x1b[32mNot enough energy.\x1b[0m" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout  << "\x1b[32m" << this->name <<" attacks " << \
	target << " for " << this->attackDamage <<" damage!\x1b[0m"
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		std::cout  << "\x1b[32m" << this->name \
		<< " is dead\x1b[0m" << std::endl;
		 energyPoints = 0;
	}
	else
	{
		std::cout  << "\x1b[32m" << this->name << " takes " << amount << \
		" damage\x1b[0m" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "\x1b[32mNot enough energy.\x1b[0m" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "\x1b[32m"<< this->name << " recovered "\
	 << amount << "\x1b[0m" << std::endl;
	this->hitPoints += amount;
}
