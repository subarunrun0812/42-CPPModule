#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
#ifdef DEBUG
    std::cout << "ShrubberyCreationForm\t constructor called" << std::endl;
#endif
}

ShrubberyCreationForm ::~ShrubberyCreationForm()
{
#ifdef DEBUG
    std::cout << "ShrubberyCreationForm\t destructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shr)
{
#ifdef DEBUG
    std::cout << "ShrubberyCreationForm\t copy constructor called" << std::endl;
#endif
    this->target = shr.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shr)
{
#ifdef DEBUG
    std::cout << "ShrubberyCreationForm\t copy operator called" << std::endl;
#endif
    this->target = shr.target;
    return *this;
}

static void EditFile(std::string target)
{
    std::ofstream outFile(target + "_shrubbery");
    outFile << "      _-_" << std::endl;
    outFile << "   /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;
    outFile << "     //   \\\\" << std::endl;
    outFile << "    //     \\\\" << std::endl;
    outFile << "   //       \\\\" << std::endl;
    outFile << "  //         \\\\" << std::endl;
    outFile << " //           \\\\" << std::endl;
    outFile << "//             \\\\" << std::endl;
    outFile << "___________________" << std::endl;
    outFile.close();
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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
        EditFile(this->target);
        std::cout << GREEN "created tree to " << this->target
                  << "_shrubbery file" NORMAL << std::endl;

#ifdef DEBUG
        std::ifstream inFile(target + "_shrubbery");
        std::string line;
        while (std::getline(inFile, line))
            std::cout << line << std::endl;
        inFile.close();
#endif
    }
}