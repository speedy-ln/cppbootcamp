#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
public:
    Victim(std::string victim_name);
    ~Victim();
    Victim(const Victim &copy);
    Victim  &operator=(Victim const &copy);

    std::string getName() const;
    virtual void    getPolymorphed() const;

protected:
    std::string _name;
};

std::ostream&   operator<<(std::ostream &os, Victim const &copy);

#endif