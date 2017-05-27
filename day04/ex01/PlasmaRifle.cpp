#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {};
PlasmaRifle::~PlasmaRifle() {};
PlasmaRifle::PlasmaRifle(PlasmaRifle const &copy) : AWeapon("Plasma Rifle", 5, 21) { *this = copy; }
void PlasmaRifle::attack() const { std::cout << "* piouuu piouuu piouuu *" << std::endl; }
PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &copy)
{
    if (this != &copy)
        AWeapon::operator=(copy);
    return (*this);
}