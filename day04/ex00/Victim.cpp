#include "Victim.hpp"


//Coplien’s form && operators
Victim::Victim(std::string victim_name) : _name(victim_name)
{
    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim() { std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl; }

Victim::Victim(const Victim &copy)
{
    *this = copy;
    std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

std::ostream    &operator<<(std::ostream &os, Victim const &copy)
{
    os << "I'm " << copy.getName() << " and i like otters !" << std::endl;
    return (os);
}

Victim& Victim::operator=(Victim const &copy)
{
    if (this != &copy)
        _name = copy._name;
    return (*this);
}

void Victim::getPolymorphed() const { std::cout << _name << " has been turned into a cute little sheep !" << std::endl; }


//
std::string Victim::getName() const { return _name; }