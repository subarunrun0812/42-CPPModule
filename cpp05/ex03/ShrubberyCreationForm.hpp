#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string &taget);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& shr);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shr);
	void execute(const Bureaucrat &executor) const;
};

#endif