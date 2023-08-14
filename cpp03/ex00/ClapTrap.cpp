#include "ClapTrap.hpp"
		
ClapTrap::ClapTrap(const std::string name,int hitPoints,\
					int energyPoints, int attackDamage)
{
	this->name = name;
	this->hitPoints = hitPoints;
	this->energyPoints = energyPoints;
	this->attackDamage = attackDamage;
	std::cout << "Constructors with arguments" << std::endl;
}

// Canonical Form〜
ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	std::cout << "Copy Constructor" << std::endl;
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

int ClapTrap::getAttackDamege(void)
{
	return (this->attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name <<" attacks " << 
	target << "for " << this->attackDamage <<" damage!"
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is dead" << std::endl;
		 energyPoints = 0;
	}
	else
	{
		std::cout << this->name << " takes " << amount << \
		" damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << " recovered " << amount - this->hitPoints << std::endl;
	this->hitPoints = amount;
}
