#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

//オブジェクト生成時、HumanBはweaponを持っていない。
//後から、Weaponオブジェクトを保持するため
class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif
