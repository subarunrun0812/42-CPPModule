#include "Bureaucrat.hpp"

void NormalTest_0()
{
	std::cout << DELIMITER_HALF << " Normal Test 1 " << DELIMITER_HALF << std::endl;
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
	std::cout << std::endl;
}
void NormalTest_1()
{
	std::cout << DELIMITER_HALF << " Normal Test 150 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_NORMAL_0", 150);
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
	std::cout << std::endl;
}
void ErrorTest_0()
{
	std::cout << DELIMITER_HALF << " Error Test -1 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", -1);
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
	std::cout << std::endl;
}
void ErrorTest_1()
{
	std::cout << DELIMITER_HALF << " Error Test 151 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", 151);
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
	std::cout << std::endl;
}
void ErrorTest_2()
{
	std::cout << DELIMITER_HALF << " Error Test 150 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
void ErrorTest_3()
{
	std::cout << DELIMITER_HALF << " Error Test 1 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}
void ErrorTest_4()
{
	std::cout << DELIMITER_HALF << " Error Test -2147483648 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", -2147483648);
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
	std::cout << std::endl;
}
void ErrorTest_5()
{
	std::cout << DELIMITER_HALF << " Error Test 2147483647 " << DELIMITER_HALF << std::endl;
	try
	{
		Bureaucrat bureaucrat("NAME_ERRORL_0", 2147483647);
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
	std::cout << std::endl;
}

int main()
{
	// TODO
	// 等級を増減される関数を実装
	NormalTest_0();
	NormalTest_1();
	ErrorTest_0();
	ErrorTest_1();
	ErrorTest_2();
	ErrorTest_3();
	ErrorTest_4();
	ErrorTest_5();
}