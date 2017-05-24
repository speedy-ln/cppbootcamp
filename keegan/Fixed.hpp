#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int bits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(Fixed const &src);
    Fixed &operator=(Fixed const &rhs);
    bool operator>(Fixed const &rhs);
    bool operator<(Fixed const &rhs);
    bool operator>=(Fixed const &rhs);
    bool operator<=(Fixed const &rhs);
    bool operator==(Fixed const &rhs);
    bool operator!=(Fixed const &rhs);

    Fixed &operator+(Fixed const &rhs);
    Fixed &operator-(Fixed const &rhs);
    Fixed &operator*(Fixed const &rhs);
    Fixed &operator/(Fixed const &rhs);

    Fixed &operator++();
    Fixed &operator++(int);
    Fixed &operator--();
    Fixed &operator--(int);

    int getRawBits(int n) const;
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed& min(Fixed &val1, Fixed &val2);
    static Fixed& max(Fixed &val1, Fixed &val2);
    static Fixed const &min(Fixed const &val1, Fixed const &val2);
    static Fixed const &max(Fixed const &val1, Fixed const &val2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif