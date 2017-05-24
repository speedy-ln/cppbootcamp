#include "Fixed.class.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = value << fractionalBits;
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
        rawBits = obj.getRawBits(1);
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

int Fixed::getRawBits(int n) const
{
    n++;
    return rawBits;
}

void Fixed::setRawBits(int const raw) { rawBits = raw; }

std::ostream & operator<<(std::ostream &os, Fixed const &obj)
{
    os << obj.toFloat();
    return os;
}

int Fixed::toInt() const { return (rawBits >> fractionalBits); }
float Fixed::toFloat() const { return (((float)rawBits) / (1 << fractionalBits)); }

bool Fixed::operator!=(Fixed const &obj) const { return (rawBits != obj.rawBits); }
bool Fixed::operator==(Fixed const &obj) const { return (rawBits == obj.rawBits); }
bool Fixed::operator<(Fixed const &obj) const { return (rawBits < obj.rawBits); }
bool Fixed::operator<=(Fixed const &obj) const { return (rawBits <= obj.rawBits); }
bool Fixed::operator>(Fixed const &obj) const { return (rawBits > obj.rawBits); }
bool Fixed::operator>=(Fixed const &obj) const { return (rawBits >= obj.rawBits); }
Fixed& Fixed::operator*(Fixed const &obj) const { return (*new Fixed(this->toFloat() * obj.toFloat())); }
Fixed& Fixed::operator/(Fixed const &obj) const { return (*new Fixed(this->toFloat() / obj.toFloat())); }
Fixed& Fixed::operator+(Fixed const &obj) const
{
    Fixed   *sum = new Fixed();
    sum->rawBits = rawBits + obj.rawBits;
    return (*sum);
}
Fixed& Fixed::operator++(int)
{
    Fixed *copy = new Fixed(*this);
    operator++();
    return *copy;
}
Fixed& Fixed::operator++()
{
    rawBits++;
    return (*this);
}
Fixed& Fixed::operator-(Fixed const &obj) const
{
    Fixed		*subtract = new Fixed();
    subtract->rawBits = rawBits - obj.rawBits;
    return (*subtract);
}
Fixed& Fixed::operator--(int)
{
    Fixed   *copy = new Fixed(*this);
    operator--();
    return (*copy);
}
Fixed& Fixed::operator--()
{
    rawBits--;
    return (*this);
}

Fixed& Fixed::min(Fixed &val1, Fixed &val2) { return ((val1.rawBits < val2.rawBits) ? val1 : val2); }
Fixed& Fixed::max(Fixed &val1, Fixed &val2) { return ((val1.rawBits > val2.rawBits) ? val1 : val2); }
Fixed const &Fixed::min(Fixed const &val1, Fixed const &val2) { return ((val1.rawBits < val2.rawBits) ? val1 : val2); }
Fixed const	&Fixed::max(Fixed const &val1, Fixed const &val2) { return ((val1.rawBits > val2.rawBits) ? val1 : val2); }
