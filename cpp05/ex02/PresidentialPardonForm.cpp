#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
#ifdef DEBUG
    std::cout << "PresidentialPardonForm\t constructor called" << std::endl;
#endif
}

PresidentialPardonForm ::~PresidentialPardonForm()
{
#ifdef DEBUG
    std::cout << "PresidentialPardonForm\t destructor called" << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pre)
{
#ifdef DEBUG
    std::cout << "PresidentialPardonForm\t copy constructor called" << std::endl;
#endif
    this->target = pre.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pre)
{
#ifdef DEBUG
    std::cout << "PresidentialPardonForm\t copy operator called" << std::endl;
#endif
    this->target = pre.target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    //besigned()で官僚の等級を確認している為、ここでは不要
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw GradeTooHighException();
    }
    else
    {
#ifdef DEBUG
        std::cout << GREEN "実行権限がある" NORMAL << std::endl;
#endif
        std::cout << this->target << "has been pardoned by Zaphod Beeblebrox"
                  << std::endl;
    }
}