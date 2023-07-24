#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string.h>
#include <iostream>

//オブジェクト生成時、HumanAはweaponを持っている
class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack() const;
};

#endif
