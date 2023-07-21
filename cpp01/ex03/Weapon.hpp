#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	//型へのconst参照を返すgetType()メンバ関数
	const std::string& getType() const;
	//パラメータとして渡された新しい型を使って
	//型を設定するsetType()メンバ関数
	void setType(const std::string& type);

};

#endif