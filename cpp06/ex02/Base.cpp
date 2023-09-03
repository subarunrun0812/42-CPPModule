#include "Base.hpp"

Base::~Base()
{
#ifdef DEBUG
	std::cout << "Base\tdestructor called" << std::endl;
#endif
}