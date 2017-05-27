#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
public:
    Sorcerer(std::string sorcerer_name, std::string sorcerer_title);
    ~Sorcerer();
    Sorcerer(Sorcerer const &copy);
    Sorcerer& operator=(Sorcerer const &copy);

    std::string getName() const;
    std::string getTitle() const;
    void    polymorph(Victim const &) const;


private:
    std::string _name;
    std::string _title;
};

std::ostream& operator<<(std::ostream &os, Sorcerer const &copy);

#endif