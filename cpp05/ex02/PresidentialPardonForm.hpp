#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& pre);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& pre);
	void execute(const Bureaucrat& executor);

};

#endif
