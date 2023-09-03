#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>  // for time()
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="

class Base
{
public:
	virtual ~Base();
};

#endif