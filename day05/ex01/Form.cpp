#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade) throw(GradeTooHighException, GradeTooLowException) : _name(name)
{
    if (signGrade < 1 || executeGrade < 1) throw (GradeTooHighException());
    else if (signGrade > 150 || executeGrade > 150) throw (GradeTooLowException());
    _signGrade = signGrade;
    _executeGrade = executeGrade;
}

Form::Form(const Form &copy) { *this=copy; }
Form::~Form() {}
Form& Form::operator=(const Form &copy)
{
    _name = copy._name;
    _signGrade = copy._signGrade;
    _executeGrade = copy._executeGrade;
    return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException)
{
    if (bureaucrat.getGrade() > _signGrade) throw (GradeTooLowException());
    _signed = true;
}

bool Form::isSigned() const { return _signed; }
const std::string & Form::getName() const { return _name; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }

std::ostream    &operator<<(std::ostream &os, Form const &form)
{
    os << form.getName() << " ";
    if (form.isSigned()) os << "signed ";
    else os << "cannot sign ";
    os << "form. Min sign grade: " << form.getSignGrade() << " , min execute grade: " << form.getExecuteGrade() << std::endl;
    return os;
}

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &copy) { *this=copy; }
char const* Form::GradeTooHighException::what() const throw() { return "Grade too high."; }
Form::GradeTooHighException& Form::GradeTooHighException::operator=(GradeTooHighException const &copy)
{
    std::exception::operator=(copy);
    return *this;
}

Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
Form::GradeTooLowException::GradeTooLowException(GradeTooHighException const &copy) { *this=copy; }
char const* Form::GradeTooLowException::what() const throw() { return "Grade too low"; }
Form::GradeTooLowException& Form::GradeTooLowException::operator=(GradeTooLowException const &copy)
{
    std::exception::operator=(copy);
    return *this;
}