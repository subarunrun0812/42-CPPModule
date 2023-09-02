#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void NormalTest_1()
{
    Intern intern;
    AForm *aForm;

    // rrf = someRandomIntern.makeForm("robotomy", "Bender");
    aForm = intern.makeForm("robotomy request", "Bender");
    delete aForm;
}

void ErrorTest_1()
{
    Intern intern;
    AForm *aForm;

    // rrf = someRandomIntern.makeForm("robotomy", "Bender");
    aForm = intern.makeForm("hoge", "Bender");
}

int main(void)
{
    NormalTest_1();
    ErrorTest_1();
}