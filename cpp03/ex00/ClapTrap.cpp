#include "ClapTrap.hpp"

//引数付きコンストラクタで初期化
ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
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

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
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

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << this->name << " attacks " << target << " for " << this->attackDamage << " damage!"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is dead" << std::endl;
		energyPoints = 0;
		hitPoints = 0;
	}
	else
	{
		std::cout << this->name << " takes " << amount << " damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return;
	}
	this->energyPoints--;
	if (this->hitPoints + amount > INT_MAX)
	{
		std::cout << "INT_MAX or higher cannot be recovered." << std::endl;
	}
	else
	{
		std::cout << this->name << " recovered " << amount << std::endl;
		this->hitPoints += amount;
	}
}
