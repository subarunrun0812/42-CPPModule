#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	RobotomyRequestForm();

public:
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &rob);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rob);
	void execute(Bureaucrat const &executor) const;
};

#endif