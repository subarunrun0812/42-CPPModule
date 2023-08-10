#include "Zombie.hpp"

//TODO:デストラクタを作成
Zombie::~Zombie()
{
	std::cout << this->name << ": has been destroyed" << std::endl;
}

Zombie::Zombie(std::string zombieName)
{
	this->name = zombieName;
	std::cout << this->name << ": create zombie object" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
