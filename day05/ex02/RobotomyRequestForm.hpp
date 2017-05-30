#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(std::string const &target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    std::string const   &getTarget() const;
//    void                beExecuted() const;

private:
    std::string _target;
};

#endif