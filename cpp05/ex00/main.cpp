#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("BIGGERST", 1);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}