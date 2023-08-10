#ifndef HARL_HPP
#define HARL_HPP

#include <string.h>
#include <iostream>

class Harl 
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain(std::string level);
};

void selectionComplain(std::string level);

#endif