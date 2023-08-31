#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bure\tdefault construcotor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bure\tdestructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
	std::cout << "Bure\tcopy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooLowException();
	}
	else if (150 < grade)
	{
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	std::cout << "decrementGrade()" << std::endl;
	if (this->grade - 1 < 1)
	{
		throw GradeTooLowException();
	}
	this->grade--;
}
void Bureaucrat::incrementGrade()
{
	std::cout << "incrementGrade()" << std::endl;
	if (150 < this->grade + 1)
	{
		throw GradeTooHighException();
	}
	this->grade++;
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}
int Bureaucrat::getGrade(void) const
{
	return (this->grade);
} 
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << *this << " couldn't sign " << form.getName()
				  << "because" << e.what() << "." << std::endl;
	}
}
void execute(Bureaucrat const &executor) const
{
	
}