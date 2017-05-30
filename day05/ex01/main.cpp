#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    Form form("Form 1", 50, 50);
    std::cout << form;

    try {
        Bureaucrat james("James", 75);
        std::cout << james;
        james.signForm(form);
        std::cout << form;
    } catch (std::exception &e){
        std::cout << "James exception caught." << std::endl;
    }

    try {
        Bureaucrat james("James", 151);
        std::cout << james;
        james.signForm(form);
        std::cout << form;
    } catch (std::exception &e){
        std::cout << "James exception caught." << std::endl;
    }

    try {
        Bureaucrat jabu("Jabu", 2);
        std::cout << jabu;
        jabu.signForm(form);
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << "Jabu exception caught." << std::endl;
    }

    try {
        Bureaucrat jabu("Jabu", 0);
        std::cout << jabu;
        jabu.signForm(form);
        std::cout << form;
    } catch (std::exception &e) {
        std::cout << "Jabu exception caught." << std::endl;
    }

    return (0);

}