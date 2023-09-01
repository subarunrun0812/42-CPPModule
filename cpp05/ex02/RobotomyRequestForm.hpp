#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string target;
	RobotomyRequestForm();
public:
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& rob);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rob);
	void execute(Bureaucrat const& executor);
};


#endif