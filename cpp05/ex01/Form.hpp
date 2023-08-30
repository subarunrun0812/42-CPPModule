#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\x1b[31m"
#define NORMAL "\x1b[0m"
#define DELIMITER_HALF "=========="

// 前方宣言
class Bureaucrat;

class Form
{
private:
    std::string name;
    bool sign;
    int gradeToSign;
    int gradeToExecute;

public:
    Form();
    Form(std::string &name, int gradeToSign, int gradeToExecute);
    // Form();
    ~Form();
    Form(const Form &form);
    Form &operator=(const Form &form);
    void beSigned(const Bureaucrat &bureaucrat);
    std::string getName() const;
    bool getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    Form(const std::string &name, int gradeToSign);
    /* ---------------- 例外クラス ---------------- */
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return RED "Form\tGrade too high" NORMAL; }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return RED "Form\tGrade too low" NORMAL; }
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif