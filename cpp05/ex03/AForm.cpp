#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
#ifdef DEBUG
	std::cout << "AForm\tconstructor called" << std::endl;
#endif
	if (gradeToSign < 1)
	{
		throw GradeTooLowException();
	}
	else if (150 < gradeToSign)
	{
		throw GradeTooHighException();
	}
}

AForm::AForm()
{
#ifdef DEBUG
	std::cout << "AForm\tdefault constructor called" << std::endl;
#endif
}
AForm::~AForm()
{
#ifdef DEBUG
	std::cout << "AForm\tdestructor called" << std::endl;
#endif
}
AForm::AForm(const AForm &aform)
	: name(aform.name), gradeToSign(aform.gradeToSign), gradeToExecute(aform.gradeToExecute)
{
#ifdef DEBUG
	std::cout << "AForm\tcopy constructor called" << std::endl;
#endif
}
AForm &AForm::operator=(const AForm &aform)
{
#ifdef DEBUG
	std::cout << "AForm\tcopy assignment operator called" << std::endl;
#endif
	this->name = aform.name;
	this->gradeToSign = aform.gradeToSign;
	this->gradeToExecute = aform.gradeToSign;
	return (*this);
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
#ifdef DEBUG
	std::cout << "フォーム\tgetGrade=" << bureaucrat.getGrade() << std::endl;
	std::cout << "〜官僚〜\tgradeToSign=" << this->gradeToSign << std::endl;
#endif
	if (bureaucrat.getGrade() > this->gradeToSign)
	{
		throw GradeTooHighException();
	}
	sign = true;
#ifdef DEBUG
	std::cout << GREEN "署名権限が付与された" NORMAL <<  std::endl;
#endif
}
std::string AForm::getName() const
{
	return (this->name);
}
bool AForm::getSign() const
{
	return (this->sign);
}
int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	os << "~~ AForm ~~" << std::endl;
	os << "Name:\t" << aform.getName() << std::endl;
	os << "Sign:\t" << aform.getSign() << std::endl;
	os << "GradeToSign:\t" << aform.getGradeToSign() << std::endl;
	os << "GradeToExecute:\t" << aform.getGradeToExecute() << std::endl;
	return (os);
}
