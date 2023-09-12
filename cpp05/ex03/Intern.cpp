#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
#ifdef DEBUG
    std::cout << "Intern\tconstructor called" << std::endl;
#endif
}
Intern::~Intern()
{
#ifdef DEBUG
    std::cout << "Intern\tdestructor called" << std::endl;
#endif
}
Intern::Intern(const Intern &intern)
{
#ifdef DEBUG
    std::cout << "Intern\tcopy constructor called" << std::endl;
#endif
    *this = intern;
}
Intern &Intern::operator=(const Intern &intern)
{
#ifdef DEBUG
    std::cout << "Intern\tcopy operator called" << std::endl;
#endif
    (void)intern;
    return *this;
}
AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string formName[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"};

    AForm *forms[] =
        {
            new PresidentialPardonForm(target),
            new RobotomyRequestForm(target),
            new ShrubberyCreationForm(target)
        };
    int flag = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if (name == formName[i])
        {
            std::cout << GREEN "Intern creates " << name << NORMAL << std::endl;
            flag = i;
        }
        else
        {
            delete forms[i];
        }
    }
    if (flag != -1)
        return forms[flag];
    std::cout << RED "Intern cannot create " << name << " form" NORMAL << std::endl;
    return NULL;
}