#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
#ifdef DEBUG
    std::cout << "RobotomyRequestForm\t constructor called" << std::endl;
#endif
}

RobotomyRequestForm ::~RobotomyRequestForm()
{
#ifdef DEBUG
    std::cout << "RobotomyRequestForm\t destructor called" << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rob)
{
#ifdef DEBUG
    std::cout << "RobotomyRequestForm\t copy constructor called" << std::endl;
#endif
    this->target = rob.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rob)
{
#ifdef DEBUG
    std::cout << "RobotomyRequestForm\t copy operator called" << std::endl;
#endif
    this->target = rob.target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw GradeTooHighException();
    }
    else
    {
#ifdef DEBUG
        std::cout << GREEN "実行権限がある" NORMAL << std::endl;
#endif
        static int i;
        if (i % 2 == 0)
            std::cout << this->target << "is corrected" << std::endl;
        else
            std::cout << this->target << "is not corrected" << std::endl;
        i++;
    }
}