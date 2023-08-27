#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\x1b[31m"
#define NORMAL "\x1b[0m"

class Bureaucrat
{
private:
	std::string name;//官僚の名前
	int grade;//1~150 (高 ~ 低)
public:
	//TODO:gradeが1~150以外のものから、例外が投げられた時のthrowの処理を作成
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& Bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	Bureaucrat(std::string name, int grade);
	std::string getName(void) const;
	int getGrade(void) const;
	/* ---------------- 例外クラス ---------------- */
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Grade too low"; }
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif