#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
public:
    Human();
    ~Human();
    const Brain brain;
    Brain getBrain();
    std::string identify() const;
};

#endif
