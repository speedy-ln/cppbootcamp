#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value = rhs.getRawBits(1);
    return *this;
}

bool Fixed::operator>(Fixed const & rhs)
{
    if (value > rhs.value)
        return true;
    else
        return false;
}

bool Fixed::operator<(Fixed const & rhs)
{
    if (value < rhs.value)
        return true;
    else
        return false;
}

bool Fixed::operator>=(Fixed const & rhs)
{
    if (value >= rhs.value)
        return true;
    else
        return false;
}

bool Fixed::operator<=(Fixed const & rhs)
{
    if (value <= rhs.value)
        return true;
    else
        return false;
}

bool Fixed::operator==(Fixed const & rhs)
{
    if (value == rhs.value)
        return true;
    else
        return false;
}

bool Fixed::operator!=(Fixed const & rhs)
{
    if (value != rhs.value)
        return true;
    else
        return false;
}

Fixed & Fixed::operator+(Fixed const & rhs)
{
    return *new Fixed(rhs.getRawBits() + this->value);
}

Fixed & Fixed::operator-(Fixed const & rhs)
{
    return *new Fixed(rhs.getRawBits() - this->value);
}

Fixed & Fixed::operator*(Fixed const & rhs)
{
    return *new Fixed(rhs.toFloat() * toFloat());
}

Fixed & Fixed::operator/(Fixed const & rhs)
{
    return *new Fixed(rhs.toFloat() / toFloat());
}

Fixed & Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed & Fixed::operator++(int)
{
    Fixed *copy = new Fixed(*this);
    operator++();
    return *copy;
}

Fixed & Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed & Fixed::operator--(int)
{
    Fixed *copy = new Fixed(*this);
    operator--();
    return *copy;
}

int Fixed::getRawBits(int n) const
{
    n++;
    return value;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    value = n << bits;
}

Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat() const { return (((float)value) / (1 << bits)); }

int Fixed::toInt(void) const
{
    return value >> bits;
}

Fixed& Fixed::min(Fixed &val1, Fixed &val2) { return ((val1.value < val2.value) ? val1 : val2); }
Fixed& Fixed::max(Fixed &val1, Fixed &val2) { return ((val1.value > val2.value) ? val1 : val2); }
Fixed const &Fixed::min(Fixed const &val1, Fixed const &val2) { return ((val1.value < val2.value) ? val1 : val2); }
Fixed const	&Fixed::max(Fixed const &val1, Fixed const &val2) { return ((val1.value > val2.value) ? val1 : val2); }