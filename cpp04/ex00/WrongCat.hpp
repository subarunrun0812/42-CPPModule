#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& WrongCat);
	WrongCat& operator=(const WrongCat& WrongCat);
	// 仮想関数
	virtual ~WrongCat();
	// Virtualを使用しない場合、基底クラスの方の処理内容が優先されることを知る為のWrong*クラス。
	void makeSound() const;
	std::string getType() const;
};

#endif