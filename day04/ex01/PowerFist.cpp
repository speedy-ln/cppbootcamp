#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {};
PowerFist::~PowerFist() {};
PowerFist::PowerFist(PowerFist const &copy) : AWeapon("Power Fist", 8, 50) { *this = copy; }
void PowerFist::attack() const { std::cout << "* pschhh... SBAM! *" << std::endl; }
PowerFist& PowerFist::operator=(PowerFist const &copy)
{
    if (this != &copy)
        AWeapon::operator=(copy);
    return (*this);
}