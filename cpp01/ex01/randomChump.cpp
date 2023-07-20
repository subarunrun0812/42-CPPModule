#include "Zombie.hpp"

/*
//It creates a zombie, name it, and the zombie announces itself.
ゾンビを作成し、名前を付け、ゾンビが自分自身を発表するため、
スタック領域に保存され、この関数のスコープ内で終了する
*/
void randomChump( std::string name )
{
	Zombie chump(name);
	chump.announce();
}