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

void checkGrade(int grade)
{
	// gradeの値を確認
	if (grade < 0)
	{
		throw GradeTooLowException();
	}
	else if(150 < grade)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	try
	{
		checkGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void GradeTooHighException()
{
	std::cout << RED << "grade too high exception" << NORMAL << std::endl;
}

void GradeTooLowException()
{
	std::cout << RED << "grade too low exception" << NORMAL << std::endl;
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