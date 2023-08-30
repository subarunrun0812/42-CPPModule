#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign)
    : name(name), sign(false),gradeToSign(gradeToSign), gradeToExecute(0)
{
    if (gradeToSign < 1)
    {
        throw GradeTooLowException();
    }
    else if (150 < gradeToSign)
    {
        throw GradeTooHighException();
    }
}

Form::Form()
{
    std::cout << "Form\tdefault constructor called" << std::endl;
}
Form::~Form()
{
    std::cout << "Form\tdestructor called" << std::endl;
}
Form::Form(const Form &form)
    : name(form.name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    std::cout << "Form\tcopy constructor called" << std::endl;
}
Form &Form::operator=(const Form &form)
{
    std::cout << "Form\tcopy assignment operator called" << std::endl;
    this->name = form.name;
    this->gradeToSign = form.gradeToSign;
    this->gradeToExecute = form.gradeToSign;
    return (*this);
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
        throw GradeTooHighException();
    }
    sign = true;
}
std::string Form::getName() const
{
    return (this->name);
}
bool Form::getSign() const
{
    return (this->sign);
}
int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Name:\t" << form.getName() << std::endl;
    os << "Sign:\t" << form.getSign() << std::endl;
    os << "GradeToSign:\t" << form.getGradeToSign() << std::endl;
    os << "GradeToExecute:\t" << form.getGradeToExecute() << std::endl;
    return (os);
}
