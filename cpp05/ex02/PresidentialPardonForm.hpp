#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& pre);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& pre);
	void execute(const Bureaucrat& executor) const ;

};

#endif
