#include "Weapon.hpp"

/*
クラス::メンバ関数 スコープ解決演算子
*/
// 引数のtypeでクラスのメンバ変数typeを初期化する
Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& newType)
{
	this->type = newType;
}