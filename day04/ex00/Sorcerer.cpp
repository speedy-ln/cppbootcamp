#include "Sorcerer.hpp"

//Coplien’s form && operators
Sorcerer::Sorcerer(std::string sorcerer_name, std::string sorcerer_title) : _name(sorcerer_name), _title(sorcerer_title)
{
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &copy)
{
    *this = copy;
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &copy)
{
    if (this != &copy)
    {
        _name = copy._name;
        _title = copy._title;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream &os, Sorcerer const &copy)
{
    os << "I am " << copy.getName() << ", " << copy.getTitle() << ", and I like ponies !" << std::endl;
    return (os);
}

//Getters & Setters
std::string Sorcerer::getName() const { return _name; }
std::string Sorcerer::getTitle() const { return _title; }
void Sorcerer::polymorph(Victim const &victim) const { victim.getPolymorphed(); }
