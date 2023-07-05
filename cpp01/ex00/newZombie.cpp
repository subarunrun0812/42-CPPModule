#include "Zombie.hpp"

/*
It creates a zombie, name it, and return it so you can use it outside of the function scope.
これはゾンビを作成し、名前を付けて返します。ヒープ領域に割り当てられるため、
関数のスコープ外でも使用できる。
*/
Zombie* newZombie( std::string name )
{
	//ヒープ領域で新しいオブジェクトを作成する。後に解放する必要がある。
    return new Zombie(name);
}