#include "ClapTrap.hpp"

int main(void)
{
	//(hitPoins,energyPoints,attackDamage)
	ClapTrap player("player");
	ClapTrap enemy("enemy");
	player.attack("enemy");
	enemy.takeDamage(player.getAttackDamage());
	std::cout << "enemy: hitPoints = " << enemy.getHitPoints() << std::endl;
	enemy.beRepaired(10);
	std::cout << "enemy: hitPoints = " << enemy.getHitPoints() << std::endl;
	std::cout << "enemy: energyPoints = " << enemy.getEnergyPoints() << std::endl;
	std::cout << "player: hitPoints = " << player.getHitPoints() << std::endl;
	std::cout << "player: energyPoints = " << player.getEnergyPoints() << std::endl;
}