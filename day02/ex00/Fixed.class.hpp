#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &obj);
    Fixed &operator=(Fixed const &obj);
    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int                 rawBits;
    static const int    fractionalBits;
};

#endif