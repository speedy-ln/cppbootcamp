#include "Fixed.class.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = (value * (float)(1 << this->fractionalBits) + 1);
//    this->rawBits = (int)roundf(value * (1 << this->fractionalBits));
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = value << this->fractionalBits;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(Fixed const &obj)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &obj)
        this->rawBits = obj.getRawBits(1);
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

int Fixed::getRawBits(int n) const
{
    n++;
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) { this->rawBits = raw; }

std::ostream & operator<<(std::ostream &os, Fixed const &obj)
{
    os << obj.toFloat();
    return os;
}

int Fixed::toInt() const
{
    return (this->rawBits >> this->fractionalBits);
}

float Fixed::toFloat() const
{
    return (((float)this->rawBits) / (1 << this->fractionalBits));
}