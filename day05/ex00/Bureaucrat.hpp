#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &copy);
    Bureaucrat(Bureaucrat const &copy);

    std::string const   &getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException();
        ~GradeTooHighException() throw();
        GradeTooHighException(GradeTooHighException const &copy);
        GradeTooHighException &operator=(GradeTooHighException const &copy);
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException();
        ~GradeTooLowException() throw();
        GradeTooLowException(GradeTooHighException const &copy);
        GradeTooLowException &operator=(GradeTooLowException const &copy);
    };

private:
    Bureaucrat();
    std::string _name;
    int         _grade;
};

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &copy);

#endif