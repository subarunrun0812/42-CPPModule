#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &Intern);
    AForm *makeForm(std::string name, std::string target);
};

#endif