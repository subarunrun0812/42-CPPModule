#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
private:
	const std::string name;//官僚の名前
	int grade;
public:
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw()
		{
			return "Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw()
		{
			return "Grade too low!";
		};
	};

};

#endif