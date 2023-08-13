#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
	 : ClapTrap(name,100,50,20)
{
	std::cout << "Constructor(ScavTrap)" << std::endl;

};

// Canonical Form~

ScavTrap::ScavTrap(){}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor(ScavTrap)" << std::endl;
}

//ClapTrap(scavTrap) により基底クラスのコピーコンストラクタが呼び出され、基底クラスの部分がコピーされます。
ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	//ScavTrap独自のメンバ変数がない為、何も書かない
}

ScavTrap& operator =(const ScavTrap &scavTrap)
{
	//基底クラスのコピー代入演算子を呼び出す
	ClapTrap::operator=(scavTrap);

	return *this;
}
// ~Canonical Form

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "Not enough energy." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " <<
		target << ", causing " << this->attackDamage << " points of damage!"
		<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}