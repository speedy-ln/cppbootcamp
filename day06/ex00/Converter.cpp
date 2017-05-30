#include "Converter.hpp"

Converter::Converter(const std::string &convert) : _convert(convert) {}
Converter::~Converter() {};
Converter::Converter(Converter const &copy) { *this=copy; }
Converter& Converter::operator=(Converter const &copy)
{
    _convert = copy._convert;
    return *this;
}

Converter::operator char() const
{
    double dbl = std::strtod(_convert.c_str(), NULL);
    if (isnan(dbl)) throw (ImpossibleException());
    char character = static_cast<char>(std::atoi(_convert.c_str()));
    if (!isprint(character)) throw (NonDisplayableException());
    return character;
}

Converter::operator std::string const &() const { return _convert; }

Converter::operator int() const
{
    int i = std::atoi(_convert.c_str());
    if (errno) throw (ImpossibleException());
    return i;
}

Converter::operator float() const
{
    float flt = std::atof(_convert.c_str());
//    if (errno) throw (ImpossibleException());
    return flt;
}

Converter::operator double() const
{
    double dbl = std::strtod(_convert.c_str(), NULL);
    return dbl;
}

Converter::ImpossibleException::ImpossibleException() {}
Converter::ImpossibleException::~ImpossibleException() throw() {}
char const* Converter::ImpossibleException::what() const throw() { return ("impossible"); }

Converter::NonDisplayableException::NonDisplayableException() {}
Converter::NonDisplayableException::~NonDisplayableException() throw() {}
char const* Converter::NonDisplayableException::what() const throw() { return "Non displayable"; }

std::ostream &operator<<(std::ostream &os, Converter const &converter)
{
    os << static_cast<std::string const &>(converter);
    return os;
}
