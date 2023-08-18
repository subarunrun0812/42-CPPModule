#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
private:
	const std::string name;//官僚の名前
	int grade;//1~150 (高 ~ 低)
public:
	//TODO:gradeが1~150以外のものから、例外が投げられた時のthrowの処理を作成
	void GradeTooHighException();
	void GradeTooLowException();
	std::string getName(void) const;
	int getGrade(void) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif