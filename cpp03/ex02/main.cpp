#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	//(hitPoins,energyPoints,attackDamage)
	ClapTrap player("Player",100,20,20);
	ScavTrap scav("scav");
	FragTrap frag("frag");

	std::cout << "scav: hitPoints = " << scav.getHitPoints() << std::endl;
	player.attack("scav");
	scav.takeDamage(player.getAttackDamage());
	std::cout << "scav: hitPoints = " << scav.getHitPoints() << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	return 0;
}
