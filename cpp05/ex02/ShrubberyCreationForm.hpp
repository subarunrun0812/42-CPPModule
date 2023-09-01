#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
class ShrubberyCreationForm : public Form
{
private:
	std::string target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string taget);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& shr);
	void execute(const Bureaucrat& executor) const;

};

#endif