#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap player("player",10,10,1);
	ClapTrap enemy("enemy",10,10,1);
	player.attack("enemy");
	enemy.takeDamage(player.getAttackDamege());
	enemy.beRepaired(enemy.getAttackDamege());
	std::cout << "enemy: hitPoints = " << enemy.getHitPoints() << std::endl;
	std::cout << "enemy: energyPoints = " << enemy.getEnergyPoints() << std::endl;
	std::cout << "player: hitPoints = " << player.getHitPoints() << std::endl;
	std::cout << "player: energyPoints = " << player.getEnergyPoints() << std::endl;


}