#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="
#define SUCCESS 0
#define FAILE 1


#include <iostream>
#include <stack>
#include <sstream>


int ReversePolishNotation(std::string line);
class ErrorTokenize : public std::exception
{
	const char* what() const throw()
	{
		return (RED "Error: tokenize" NORMAL);
	}
};

class ErrorResult : public std::exception
{
	const char* what() const throw()
	{
		return (RED "Error: result" NORMAL);
	}
};

class ErrorOperator : public std::exception
{
	const char* what() const throw()
	{
		return (RED "Error: どの四則演算にも一致しなかった" NORMAL);
	}
};

class ErrorNumber : public std::exception
{
	const char* what() const throw()
	{
		return (RED "Error: Number" NORMAL);
	}
};

#endif