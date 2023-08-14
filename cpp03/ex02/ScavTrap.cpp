#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
	 : ClapTrap(name,100,50,20)
{
	std::cout << "[ScavTrap] Constructors with arguments" << std::endl;

};

// Canonical Form~
ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] Default Constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor" << std::endl;
}

//ClapTrap[scavTrap] により基底クラスのコピーコンストラクタが呼び出され、基底クラスの部分がコピーされます。
ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "[ScavTrap] Copy Constructor" << std::endl;
	//ScavTrap独自のメンバ変数がない為、何も書かない
}

ScavTrap& ScavTrap::operator =(const ScavTrap &scavTrap)
{
	//基底クラスのコピー代入演算子を呼び出す
	ClapTrap::operator=(scavTrap);

	return *this;
}
// ~Canonical Form

void ScavTrap::guardGate()
{
	std::cout  << this->name << " is now in Gate keeper mode" << std::endl;
}