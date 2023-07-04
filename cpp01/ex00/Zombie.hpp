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
		void announce(void);
		std::string get_name(void);
		void set_name(std::string);

}


void randomChump( std::string name );

Zombie* newZombie( std::string name );