#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat james("James", 2);
        std::cout << james;
        james.incrementGrade();
        std::cout << james;
        james.incrementGrade();
        std::cout << james;
    } catch (std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    try {
        Bureaucrat james("James", 149);
        std::cout << james;
        james.decrementGrade();
        std::cout << james;
        james.decrementGrade();
        std::cout << james;
    } catch (std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    try{
        Bureaucrat johnny("Johnny", 0);
    } catch (std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    try{
        Bureaucrat johnny("Johnny", 151);
    } catch (std::exception &e) {
        std::cout << "Exception caught" << std::endl;
    }

    return (0);

}