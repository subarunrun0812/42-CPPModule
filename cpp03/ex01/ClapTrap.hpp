#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap
{
	//ScavTrapからアクセスできるようにprotectedに変更
	protected:
		std::string name; // コンストラクタに渡す引数
		int hitPoints; // 体力値
		int energyPoints;
		int attackDamage;

	public:
		ClapTrap(const std::string name);
		ClapTrap(const std::string name, int hitPoints, \
			int energyPoints, int attackDamage);;
		~ClapTrap();			
		int getHitPoints(void);
		int getEnergyPoints(void);
		int getAttackDamage(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

#endif