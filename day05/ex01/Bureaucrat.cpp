#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1) throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150) throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) { *this = copy; }
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &copy) { (void)copy; return (*this); }
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1) throw (Bureaucrat::GradeTooHighException());
    _grade--;
}
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150) throw (Bureaucrat::GradeTooLowException());
    _grade++;
}

const std::string & Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &copy)
{
    os << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
    return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &copy) { *this = copy; }
Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &copy)
{
    std::exception::operator=(copy);
    return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooHighException const &copy) { *this=copy; }
Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &copy)
{
    std::exception::operator=(copy);
    return *this;
}

const char * Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low."; }
const char * Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high."; }

void Bureaucrat::signForm(Form &form) const
{

    try {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }

}