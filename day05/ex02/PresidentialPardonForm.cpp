#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

    std::string const   &getTarget() const;
//    void                beExecuted();

private:
    std::string _target;
    PresidentialPardonForm();
};

#endif