#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
#ifdef DEBUG
	std::cout << "Bure\tdefault construcotor called" << std::endl;
#endif
}

Bureaucrat::~Bureaucrat()
{
#ifdef DEBUG
	std::cout << "Bure\tdestructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
#ifdef DEBUG
	std::cout << "Bure\tcopy constructor called" << std::endl;
#endif
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
#ifdef DEBUG
	std::cout << "Bure\tcopy operator called" << std::endl;
#endif
	this->grade = bureaucrat.getGrade();
	this->name = bureaucrat.getName();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
#ifdef DEBUG
	std::cout << "Bure\t constructor called" << std::endl;
#endif
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

void Bureaucrat::signForm(AForm &form)
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

void Bureaucrat::executeForm(const AForm &aform)
{
	try
	{
		aform.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << this->name << " couldn't execute " << aform.getName() << " because " << e.what() << std::endl;
	}
}