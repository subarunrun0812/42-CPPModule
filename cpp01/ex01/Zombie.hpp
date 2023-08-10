#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <stdio.h>
#include <string.h>
#include <iostream>

// 
class Zombie
{
	private:
		std::string name;
	public:
		//コンストラクタ
		Zombie();
		//デストラクタ
		~Zombie();
		void setName(std::string name);
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

void randomChump( std::string name );

Zombie* newZombie( std::string name );

#endif