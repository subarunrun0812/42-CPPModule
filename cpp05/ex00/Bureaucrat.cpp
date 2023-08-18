#include "Bureaucrat.hpp"


std::string Bureaucrat::getName(void) const
{
	return (this->name);
}
int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

/*
TODO: <name>, bureaucrat grade <grade>.
*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{

}