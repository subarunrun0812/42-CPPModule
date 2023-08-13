#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name)\
 : ClapTrap(name,100,100,30)
{
	std::cout << "Constructor(FragTrap)" << std::endl;
}

FragTrap::FragTrap()
{
}
FragTrap::FragTrap(const FragTrap &flagTrap) : ClapTrap(flagTrap)
{
	//FragTrap独自のメンバ変数が無い為、何も書かない
}
FragTrap& FragTrap::operator=(const FragTrap &flagTrap)
{
	//基底クラスのコピー代入演算子を呼び出す
	ClapTrap::operator=(flagTrap);

	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "Destructor(FragTrap)" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->name << " requests high fives" << std::endl;
}