#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define LENGTH 4

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

//========== 例外クラス ==========
class NotFindIterator : public std::exception
{
	const char* what() const throw()
	{
		return (RED "対象の整数がSTLコンテナから見つからなかった" NORMAL);
	}
};


template <typename T>
typename T::iterator EasyFind(T container, int num)
{
	typename T::iterator res = \
		std::find(container.begin(), container.end(), num);
	if (res == container.end())
	{
		throw NotFindIterator();
	}
	return (res);
}


#endif