#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

#define RED "\x1b[31m"
#define NORMAL "\x1b[0m"
#define DELIMITER_HALF "=========="

// 前方宣言
class AForm;

class Bureaucrat
{
private:
	std::string name; // 官僚の名前
	int grade;		  // 1~150 (高 ~ 低)
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& Bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	Bureaucrat(std::string name, int grade);
	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& aform);
	void executeForm(const AForm& aform);

	/* ---------------- 例外クラス ---------------- */
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return RED "Bure: Grade too high" NORMAL; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return RED "Bure: Grade too low" NORMAL; }
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif