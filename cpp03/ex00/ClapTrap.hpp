#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap
{
private:
	std::string name; // コンストラクタに渡す引数
	// TODO:int -> unsing int に置き換え
	int hitPoints; // 体力値
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(const std::string name);
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	int getHitPoints(void);
	int getEnergyPoints(void);
	int getAttackDamage(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif