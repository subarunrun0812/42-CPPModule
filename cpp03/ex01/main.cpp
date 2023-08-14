#include "ScavTrap.hpp"

int main() {
	// ClapTrapクラスのインスタンスを作成
	ClapTrap player("player", 10, 10, 1);
	ClapTrap enemy("enemy", 10, 10, 1);
	player.attack("enemy");
	enemy.takeDamage((unsigned int)player.getAttackDamage());
	player.beRepaired(5);

	// ScavTrapクラスのインスタンスを作成
	ScavTrap scav_player("scav_player");
	ScavTrap scav_enemy("scav_enemy");
	scav_player.attack("scav_enemy");
	scav_player.guardGate();
	scav_enemy.takeDamage(scav_player.getAttackDamage());
	scav_enemy.beRepaired(5);
	std::cout << "scav_player: hitPoints = " << scav_player.getHitPoints() << std::endl;
	std::cout << "scav_player: energyPoints = " << scav_player.getEnergyPoints() << std::endl;
	std::cout << "scav_enemy: hitPoints = " << scav_enemy.getHitPoints() << std::endl;
	std::cout << "scav_enemy: energyPoints = " << scav_enemy.getEnergyPoints() << std::endl;

	return 0;
}