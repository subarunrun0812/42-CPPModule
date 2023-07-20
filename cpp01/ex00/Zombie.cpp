#include "Zombie.hpp"

//TODO:デストラクタを作成
Zombie::~Zombie()
{
	std::cout << this->name << ": has been destroyed" << std::endl;
}

Zombie::Zombie(std::string zombieName)
{
	std::cout << "create zombie object" << std::endl;
	this->name = zombieName;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
