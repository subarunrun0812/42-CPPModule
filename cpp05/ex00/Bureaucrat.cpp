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
		// throw GradeTooLowException();
	}
	else if (150 < grade)
	{
		// throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	// TODO: throwを投げる処理を行う
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (150 < grade)
	{
		throw GradeTooHighException();
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
	os << bureaucrat.getName() << ":" << bureaucrat.getGrade();
	return os;
}