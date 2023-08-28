#include "Form.hpp"

Form::Form(std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
}
// Form::Form()
// {
//     std::cout << "Form\tdefault constructor called" << std::endl;
// }
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
    // return (*this);
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
int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}
int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}