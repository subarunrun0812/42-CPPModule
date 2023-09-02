#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define NORMAL "\x1b[0m"
#define LINE "=========="

// 前方宣言
class Bureaucrat;

// 抽象クラス
class AForm
{
private:
	std::string name;
	bool sign;
	int gradeToSign;	// 署名の権限
	int gradeToExecute; // 実行の権限

public:
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	// AForm();
	virtual ~AForm();
	AForm(const AForm &aform);
	AForm &operator=(const AForm &aform);
	void beSigned(const Bureaucrat &bureaucrat);
	std::string getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	AForm(const std::string &name, int gradeToSign);
	virtual void execute(Bureaucrat const &executor) const = 0;
	/* ---------------- 例外クラス ---------------- */
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return RED "AForm Grade too high" NORMAL; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() { return RED "AForm Grade too low" NORMAL; }
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);

#endif