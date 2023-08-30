#include "Bureaucrat.hpp"
#include "Form.hpp"

void NormalTest_0()
{
	std::cout << DELIMITER_HALF << " Normal Test 1 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_NORMAL_0", 11);
		Form form("formName", 10);
		bureaucrat.signForm(form);

		std::cout << form << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	NormalTest_0();
}