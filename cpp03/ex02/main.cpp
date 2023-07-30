#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap player("Player");
	ScavTrap scav("scav");
	FragTrap frag("frag");

	player.attack("Enemy");
	scav.guardGate();
	frag.highFivesGuys();

	return 0;
}
