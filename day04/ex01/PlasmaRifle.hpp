#ifndef PLASMA_RIFLE_HPP
#define PLASMA_RIFLE_HPP

//#include <string>
//#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();
    PlasmaRifle &operator=(PlasmaRifle const &copy);
    PlasmaRifle(PlasmaRifle const &copy);

    void    attack() const;

private:
    std::string _name;
//    int         _apcost;
//    int         _damage;
};

#endif