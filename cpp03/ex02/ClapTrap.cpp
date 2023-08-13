#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
{
	this->name = name;
	std::cout << "Constructor(ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, int hitPoints, \
	int energyPoints, int attackDamage)
{
	this->name = name;
	this->hitPoints = hitPoints;
	this->energyPoints = energyPoints;
	this->attackDamage = attackDamage;
	std::cout << "Constructor(ClapTrap)" << std::endl;
}

// Canonical Form~
ClapTrap::ClapTrap(){}

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
}

ClapTrap& ClapTrap::operator =(const ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return *this;
}
// ~Canonical Form

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
	//TODO: 攻撃できない場合、takeDamage()も呼ばれないようにする
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " <<
		target << ", causing " << this->attackDamage << " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " took " << amount \
		<< " damage." << std::endl;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << this->name << " recovered " << amount << std::endl;
	if ((this->hitPoints + amount) >= 10)
		this->hitPoints = 10;
	else
		this->hitPoints += amount;
}
