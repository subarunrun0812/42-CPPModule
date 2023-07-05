#include "Zombie.hpp"

//TODO:デストラクタを作成
Zombie::~Zombie()
{

}
Zombie::Zombie(std::string zombieName) : name(zombieName)
{
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main(void)
{
    Zombie *zombie = newZombie("Foo");
    zombie->announce();

}