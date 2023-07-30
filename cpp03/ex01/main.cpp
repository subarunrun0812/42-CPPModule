#include "ScavTrap.hpp"

int main() {
	// ClapTrapクラスのインスタンスを作成
	ClapTrap player("player", 10, 10, 1);
	ClapTrap enemy("enemy", 10, 10, 1);
	player.attack("enemy");
	enemy.takeDamage((unsigned int)player.getAttackDamage());
	player.beRepaired(5);

	// ScavTrapクラスのインスタンスを作成
	ScavTrap scav("player2");
	scav.attack("enemy2");
	scav.guardGate();
	scav.takeDamage(15);
	scav.beRepaired(10);

	return 0;
}