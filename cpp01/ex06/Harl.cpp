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
	//メンバ関数へのポインタの配列を定義
	void (Harl::*funcArray[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*funcArray[i])();
			return;
		}
	}
	std::cout << "Probably complaining about insignificant problems \n";
};

void selectionComplain(std::string level)
{
	std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
	Harl harl;
	int num = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			num = i + 1;
			break;
		}
	}
	switch (num)
	{
	case 0:
		std::cout << "Probably complaining about insignificant problems" << std::endl;
		break;
	case 1:
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 2:
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 3:
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
		break;
	case 4:
		harl.complain("ERROR");
		break;
	}
}