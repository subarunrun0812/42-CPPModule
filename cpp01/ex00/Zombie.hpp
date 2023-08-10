#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		//コンストラクタ
		Zombie(std::string zombieName);
		//デストラクタ
		~Zombie();
		void announce(void);
};

void randomChump( std::string name );

Zombie* newZombie( std::string name );

#endif