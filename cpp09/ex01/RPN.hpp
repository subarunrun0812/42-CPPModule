#ifndef RPN_HPP
#define RPN_HPP

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
	const char* what() const throw();
};

class ErrorResult : public std::exception
{
	const char* what() const throw();
};

class ErrorOperator : public std::exception
{
	const char* what() const throw();
};

class ErrorNumber : public std::exception
{
	const char* what() const throw();
};

#endif