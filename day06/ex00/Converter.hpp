#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <errno.h>
#include <cmath>

class Converter
{
public:
    Converter(std::string const &convert);
    ~Converter();
    Converter(Converter const &copy);
    Converter &operator=(Converter const &copy);

    operator std::string const &(void) const;
    operator char() const;
    operator int() const;
    operator float() const;
    operator double()const;


    class ImpossibleException : public std::exception
    {
    public:
        ImpossibleException();
        ~ImpossibleException() throw();
        char const *what() const throw();
    };

    class NonDisplayableException : public std::exception
    {
    public:
        NonDisplayableException();
        ~NonDisplayableException() throw();
        char const *what() const throw();
    };

private:
    Converter();
    std::string _convert;
};

std::ostream &operator<<(std::ostream &os, Converter const &convert);

#endif