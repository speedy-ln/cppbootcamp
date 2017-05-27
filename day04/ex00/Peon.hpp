#ifndef PEON_HPP
#define PEON_HPP

#include <string>
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
public:
    Peon(std::string peon_name);
    ~Peon();
    Peon(const Peon &copy);
    Peon    &operator=(Peon const &copy);

    void    getPolymorphed(void) const;
};

#endif