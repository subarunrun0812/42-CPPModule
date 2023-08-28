#include "Bureaucrat.hpp"

void NormalTest_0()
{
	std::cout << DELIMITER_HALF << " Normal Test 0 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_NORMAL_0", 1);
		std::cout << bureaucrat << std::endl;
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
void ErrorTest_0()
{
	std::cout << DELIMITER_HALF << " Error Test 0 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", 200);
		std::cout << bureaucrat << std::endl;
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
	ErrorTest_0();
}