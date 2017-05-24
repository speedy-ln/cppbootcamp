#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed();
    Fixed(const Fixed &obj);
    Fixed   &operator=(Fixed const &obj);
    int     getRawBits() const;
    int     getRawBits(int n) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

private:
    int                 rawBits;
    static const int    fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &os, Fixed const &obj);

#endif