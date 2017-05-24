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
    int                 getRawBits() const;
    int                 getRawBits(int n) const;
    void                setRawBits(int const raw);
    float               toFloat(void) const;
    int                 toInt(void) const;

    Fixed               &operator=(Fixed const &obj);
    bool	            operator>(Fixed const &obj) const;
    bool	            operator<(Fixed const &obj) const;
    bool	            operator>=(Fixed const &obj) const;
    bool	            operator<=(Fixed const &obj) const;
    bool	            operator==(Fixed const &obj) const;
    bool	            operator!=(Fixed const &obj) const;
    Fixed	            &operator+(Fixed const &obj) const;
    Fixed	            &operator-(Fixed const &obj) const;
    Fixed	            &operator*(Fixed const &obj) const;
    Fixed	            &operator/(Fixed const &obj) const;
    Fixed	            &operator++(void);
    Fixed	            &operator++(int);
    Fixed	            &operator--(void);
    Fixed	            &operator--(int);

    static Fixed		&min(Fixed &val1, Fixed &val2);
    static Fixed		&max(Fixed &val1, Fixed &val2);
    static Fixed const	&min(Fixed const &val1, Fixed const &val2);
    static Fixed const	&max(Fixed const &val1, Fixed const &val2);

private:
    int                 rawBits;
    static const int    fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &os, Fixed const &obj);

#endif