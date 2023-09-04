#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="

#include <iostream>

template <typename T>
void swap(T& num1, T& num2)
{
	T tmp;
	tmp = num1;
	num1 = num2;
	num2 = tmp;
}

template <typename T>
T min(T num1, T num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

template <typename T>
T max(T num1, T num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

#endif