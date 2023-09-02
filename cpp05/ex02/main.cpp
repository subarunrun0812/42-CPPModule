#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void Form_1()
{
    std::cout << std::endl
              << LINE " FORM_1 ShrubberyCreationForm " LINE << std::endl;
    Bureaucrat bure("bure", 136);
    ShrubberyCreationForm form1("Shrubbery");
    try
    {
        bure.signForm(form1);
        bure.executeForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Form_2()
{
    std::cout << std::endl
              << LINE " FORM_2 RobotomyRequestForm" LINE << std::endl;
    Bureaucrat bure("bure", 44);
    RobotomyRequestForm form2("Shrubbery");
    try
    {
        bure.signForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Form_3()
{
    std::cout << std::endl
              << LINE " FORM_3 PresidentialPardonForm" LINE << std::endl;
    Bureaucrat bure("bure", 4);
    PresidentialPardonForm form3("President");
    try
    {
        bure.signForm(form3);
        bure.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
void OnlySigned_Form_1()
{
    std::cout << std::endl
              << LINE " OnlySigned_Form_1 ShrubberyCreationForm " LINE << std::endl;
    Bureaucrat bure("bure", 145);
    ShrubberyCreationForm form1("Shrubbery");
    try
    {
        bure.signForm(form1);
        bure.executeForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void OnlySigned_Form_2()
{
    std::cout << std::endl
              << LINE " OnlySigned_Form_2 RobotomyRequestForm" LINE << std::endl;
    Bureaucrat bure("bure", 72);
    RobotomyRequestForm form2("Shrubbery");
    try
    {
        bure.signForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void OnlySigned_Form_3()
{
    std::cout << std::endl
              << LINE " OnlySigned_Form_3 PresidentialPardonForm" LINE << std::endl;
    Bureaucrat bure("bure", 25);
    PresidentialPardonForm form3("President");
    try
    {
        bure.signForm(form3);
        bure.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
void Error_Form_1()
{
    std::cout << std::endl
              << LINE " Error_Form_1 ShrubberyCreationForm " LINE << std::endl;
    Bureaucrat bure("bure", 146);
    ShrubberyCreationForm form1("Shrubbery");
    try
    {
        bure.signForm(form1);
        bure.executeForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Error_Form_2()
{
    std::cout << std::endl
              << LINE " Error_Form_2 RobotomyRequestForm" LINE << std::endl;
    Bureaucrat bure("bure", 73);
    RobotomyRequestForm form2("Shrubbery");
    try
    {
        bure.signForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
        bure.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Error_Form_3()
{
    std::cout << std::endl
              << LINE " Error_Form_3 PresidentialPardonForm" LINE << std::endl;
    Bureaucrat bure("bure", 26);
    PresidentialPardonForm form3("President");
    try
    {
        bure.signForm(form3);
        bure.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    Form_1();
    Form_2();
    Form_3();
    OnlySigned_Form_1();
    OnlySigned_Form_2();
    OnlySigned_Form_3();
    Error_Form_1();
    Error_Form_2();
    Error_Form_3();
    return (0);
}