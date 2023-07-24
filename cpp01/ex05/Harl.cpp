#include "Harl.hpp"
#include <map>

void Harl::debug()
{
	std::cout << "\x1b[32m[Debug] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\x1b[0m";
}

void Harl::info()
{
	std::cout << "\x1b[32m[Info] I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger!\n\x1b[0m";
}

void Harl::warning()
{
	std::cout << "\x1b[33m[Warning] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n\x1b[0m";
}

void Harl::error()
{
	std::cout << "\x1b[31m[Error] This is unacceptable! I want to speak to the manager now.\n\x1b[0m";
}

void Harl::complain(std::string level)
{
	// このマップのキーはstd::string型で、値はHarlクラスのメンバ関数を指す関数ポインタ
	std::map<std::string, void (Harl::*)()> levelFuncs;
	levelFuncs["DEBUG"] = &Harl::debug;
	levelFuncs["INFO"] = &Harl::info;
	levelFuncs["WARNING"] = &Harl::warning;
	levelFuncs["ERROR"] = &Harl::error;

	if (levelFuncs.count(level) > 0)
	{
		//対応するメンバ関数を呼び出しています。関数ポインタを使用して、
		//levelに対応するHarlクラスのメンバ関数を呼び出しています。
		//例えば、levelが"DEBUG"であれば、Harl::debug関数が呼び出されます。
		(this->*levelFuncs[level])();
	}
	else
	{
		std::cout << "Invalid level!\n";
	}
};
