#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\x1b[31m"
#define NORMAL "\x1b[0m"
#define DELIMITER_HALF "=========="

class Form
{
private:
    std::string name;
    bool sign;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form(std::string &name, int gradeToSign, int gradeToExecute);
    // Form();
    ~Form();
    Form(const Form &form);
    Form &operator=(const Form &form);
    void beSigned(const Bureaucrat &bureaucrat);
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    // TODO:<<のオーバーロード

    /* ---------------- 例外クラス ---------------- */
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return RED "Grade too high" NORMAL; }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return RED "Grade too low" NORMAL; }
    };
};

#endif