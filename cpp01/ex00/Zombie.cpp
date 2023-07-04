#include "Zombie.hpp"

//TODO:デストラクタを作成


void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name(void)
{
    return (this->name);
}

void Zombie::set_name(std::string str)
{
    this->name = str;
}

//It creates a zombie, name it, and return it so you can use it outside of the function scope.
Zombie* newZombie( std::string name )
{
    Zombie *tmp_zombie;
    tmp_zombie->set_name(name);
    return (tmp_zombie);
}

//It creates a zombie, name it, and the zombie announces itself.
void randomChump( std::string name )
{

}

int main(void)
{
    Zombie *zombie = newZombie("Foo");
    zombie->announce();

}