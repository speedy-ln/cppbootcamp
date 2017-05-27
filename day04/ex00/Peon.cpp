#include "Peon.hpp"

Peon::Peon(std::string peon_name) : Victim(peon_name) { std::cout << "Zog zog." << std::endl; }
Peon::~Peon() { std::cout << "Bleuark..." << std::endl; }
Peon::Peon(const Peon &copy) : Victim(copy) { *this = copy; std::cout << "Zog zog." << std::endl; }
Peon& Peon::operator=(Peon const &copy)
{
    if (this != &copy)
        Victim::operator=(copy);
    return (*this);
}
void Peon::getPolymorphed() const { std::cout << _name << " has been turned into a pink pony !" << std::endl; }