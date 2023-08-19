#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "construcotor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	if (1 <= grade && grade <= 150)
	{
		this->grade = grade;
	}
	else
	{
		// TODO:無効な値の為、throw処理を投げる
	}
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}
int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}
/*
TODO: <name>, bureaucrat grade <grade>.
*/
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getGrade();
	return os;
}