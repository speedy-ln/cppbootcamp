#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain
{
public:
    std::string identify() const;
    Brain();

private:
    std::string address;
};

#endif
